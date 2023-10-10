/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:13:22 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 18:38:03 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_map_allocate(t_layout *layout, char **argv)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	layout->n_row = ft_count_lines(argv);
	if (layout->n_row <= 2)
		error_msg_and_free("Invalid map shape", NULL);
	layout->map = ft_calloc(layout->n_row + 1, sizeof(char *));
	if (layout->map == NULL)
		error_msg_and_free("Memory allocation failed", NULL);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < layout->n_row)
		layout->map[i++] = get_next_line(fd);
	layout->n_col = ft_strlen(layout->map[0]) - 1;
	i = 0;
	while (i < layout->n_row)
	{
		if (ft_strlen(layout->map[i++]) != layout->n_col + 1)
			error_msg_and_free("The map must be rectangular", layout->map);
	}
	ft_layout_struct_updater(layout);
	layout->move_cnt = 1;
	close(fd);
}

int	ft_count_lines(char **argv)
{
	int		line_cnt;
	char	*line;
	int		fd;

	line_cnt = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		line_cnt++;
	}
	free(line);
	close(fd);
	return (line_cnt);
}

void	ft_layout_struct_updater(t_layout *layout)
{
	int	i;
	int	j;

	i = 0;
	while (layout->map[i])
	{
		j = 0;
		while (layout->map[i][j])
		{
			if (layout->map[i][j] == 'C')
				layout->n_collect++;
			if (layout->map[i][j] == 'P')
				layout->n_player++;
			if (layout->map[i][j] == 'E')
				layout->n_exit++;
			if (layout->map[i][j] == 'G')
				layout->n_enemy++;
			if (!ft_strchr("01CEP\n", layout->map[i][j]))
				layout->inv_char = 1;
			j++;
		}
		i++;
	}
}

void	ft_player_and_exit_coordinates(t_layout *layout)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (layout->map[i])
	{
		j = 0;
		while (layout->map[i][j])
		{
			if (layout->map[i][j] == 'P')
			{
				layout->player_x = i;
				layout->player_y = j;
			}
			if (layout->map[i][j] == 'E')
			{
				layout->exit_x = i;
				layout->exit_y = j;
			}
			j++;
		}
		i++;
	}
}

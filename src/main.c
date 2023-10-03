/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:56:33 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/03 19:02:46 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_layout	layout;

	ft_check_params(argc, argv);
	ft_memset(&layout, 0, sizeof(layout));
	ft_map_allocate(&layout, argv);
	ft_map_validations(&layout);
	return (0);
}

void	ft_map_validations(t_layout *layout)
{
	if (!ft_first_and_last(layout))
		error_msg_and_free("Invalid borders", NULL);
}

int	ft_first_and_last(t_layout *layout)
{
	int check;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (layout->map[0][i] == '1')
		i++;
	while (layout->map[layout->n_row - 1][j] == '1')
		j++;
	if ((i == (size_t)ft_strlen(layout->map[0]) - 1) && \
	(j == (size_t)ft_strlen(layout->map[layout->n_row - 1]) - 1))
		check = 1;
	else
		check = 0;
	return (check);
}


void	ft_map_allocate(t_layout *layout, char **argv)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	layout->n_row = ft_count_lines(argv);
	if (layout->n_row <= 2)
		error_msg_and_free("Invalid map shape", NULL);
	layout->map = malloc(sizeof(char *) * (layout->n_row + 1));
	fd = open(argv[1], O_RDONLY);
	while (i < layout->n_row)
	{
		layout->map[i] = get_next_line(fd);
		i++;
	}
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
		line = get_next_line(fd);
		line_cnt++;
	}
	close(fd);
	return (line_cnt);
}

void	ft_check_params(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		error_msg_and_free("Number of arguments not supported", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_and_free("file not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	close(fd);
}

int	error_msg_and_free(char *msg, char **map)
{
	while (map)
	{
		free(*map);
		map++;
	}
	free(map);
	ft_printf("%sError\n%s%s", RED, msg, DEFAULT);
	exit (0);
}


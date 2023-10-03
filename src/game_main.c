/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:19:19 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/02 19:52:28 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	char		**map;
	t_layout	layout;
	map = check_params(argc, argv &layout);
	init_game(map, lay);
	return (0);
}

char	**check_params(int argc, char **argv, t_layout *layout)
{
	int	fd;
	if (argc != 2)
		error_msg_and_free("Invalid number of Arguments", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_and_free("File not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	return (check_map(fd, layout));
}

char	**check_map(int fd, t_layout *layout)
{
	char		*map_str;
	char		**map;
	t_map_error	map_err;
	map_err = ft_memset_map_error();
	layout = ft_memset_layout();
	ft_read_layout(fd, layout, &map_err, &map_str);
	ft_print_map_error(&map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg_and_free("Map memory allocation failed", NULL);
	return (map);
}

void	ft_read_layout(int fd, t_layout *layout, t_map_error *map_err, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!layout->col_cnt)
				error_msg_and_free("Map is empty", map_str);
			else
				ft_check_layout(last_line, map_err, layout, 1);
			free(last_line);
		}
		free(last_line);

	}


}

t_map_error ft_memset_map_error()
{
	t_map_error map_err;

	map_err.inv_exit = 0;
	map_err.inv_player = 0;
	map_err.inv_collect = 0;
	map_err.inv_shape = 0;
	map_err.inv_border = 0;
	map_err.inv_char = 0;
	return (map_err);
}

t_layout ft_memset_layout()
{
	t_layout layout;

	layout.row_cnt = 0;
	layout.col_cnt = 0;
	layout.exit = 0;
	layout.player = 0;
	layout.enemy = 0;
	layout.collect = 0;
	return (layout);
}

int	error_msg_and_free(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str)
	ft_printf("%sError\n%s%s", RED, msg, DEFAULT);
	exit (0);
}

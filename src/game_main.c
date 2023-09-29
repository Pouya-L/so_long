/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:19:19 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/29 15:31:30 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (fd < 0)
		error_msg_and_free("File not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	return (check_map(fd, layout));
}



int	error_msg_and_free(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str)
	ft_printf("%sError\n%s%s", RED, msg, DEFAULT);
	exit (0);
}

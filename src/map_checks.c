/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:29:33 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:06 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_params(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_msg_and_free("Number of arguments not supported", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_and_free("File not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	close(fd);
}

void	ft_map_validations(t_layout *layout)
{
	if (!ft_top_and_bottom_border(layout) || !left_and_right_border(layout))
		error_msg_and_free("Invalid borders", layout->map);
	if (layout->n_player != 1)
		error_msg_and_free("Invalid number of Players", layout->map);
	if (layout->n_exit != 1)
		error_msg_and_free("Invalid number of Exits", layout->map);
	if (layout->n_collect < 1)
		error_msg_and_free("Invalid number of Collectibles", layout->map);
	if (layout->inv_char == 1)
		error_msg_and_free("Invalid chars present in the map", layout->map);
	if (!map_copy_and_check(layout))
		error_msg_and_free("No path to exit or collectibles", layout->map);
}

int	ft_top_and_bottom_border(t_layout *layout)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 1;
	while (i < layout->n_col && j < layout->n_col)
	{
		if (layout->map[0][i++] != '1')
		{
			check = 0;
			break ;
		}
		if (layout->map[layout->n_row - 1][j++] != '1')
		{
			check = 0;
			break ;
		}
	}
	i = 0;
	return (check);
}

int	left_and_right_border(t_layout *layout)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 1;
	while (i < layout->n_row && j < layout->n_row)
	{
		if (layout->map[i++][0] != '1')
		{
			check = 0;
			break ;
		}
		if (layout->map[j++][layout->n_col - 1] != '1')
		{
			check = 0;
			break ;
		}
	}
	return (check);
}

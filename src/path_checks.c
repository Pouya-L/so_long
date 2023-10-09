/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:40 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/09 17:35:35 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_copy_and_check(t_layout *layout)
{
	char**	map_copy;
	size_t	i;

	i = 0;
	layout->collect_path_check = layout->n_collect;
	map_copy = ft_calloc(layout->n_row + 1, sizeof(char *));
	while (i < layout->n_row)
	{
		map_copy[i] = ft_strdup(layout->map[i]);
		i++;
	}
	ft_check_path(layout, layout->player_x, layout->player_y, map_copy);
	free_2D_array(map_copy);
	if (layout->collect_path_check == 0 && layout->exit_path_check == 1)
		return (1);
	else
		return (0);
}

void	ft_check_path(t_layout *layout, size_t x, size_t y, char **map_copy)
{
	if (map_copy[x][y] == 'V' || map_copy[x][y] == '1')
		return ;
	else if (map_copy[x][y] == 'C')
		layout->collect_path_check--;
	else if (map_copy[x][y] == 'E')
	{
		layout->exit_path_check = 1;
		return ;
	}
	map_copy[x][y] = 'V';
	ft_check_path(layout, x + 1, y, map_copy);
	ft_check_path(layout, x - 1, y, map_copy);
	ft_check_path(layout, x, y + 1, map_copy);
	ft_check_path(layout, x, y - 1, map_copy);
}

void	free_2D_array(char **map_copy)
{
	size_t	i;

	i = 0;
	if (map_copy != NULL)
	{
		while (map_copy[i])
		{
			free(map_copy[i]);
			i++;
		}
		free(map_copy);
	}
	map_copy = NULL;
}

int	error_msg_and_free(char *msg, char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	map = NULL;
	if (msg != NULL)
	{
	ft_printf("%sError\n%s%s\n", RED, msg, DEFAULT);
	}
	exit (0);
}


void	print_map_details(t_layout *layout)
{
	int	i;

	i = 0;
	ft_printf("Number of collumns: %d\n", layout->n_col);
	ft_printf("Number of rows: %d\n", layout->n_row);
	ft_printf("Number of players: %d\n", layout->n_player);
	ft_printf("Number of exits: %d\n", layout->n_exit);
	ft_printf("Number of enemies: %d\n", layout->n_enemy);
	ft_printf("Number of collectibles: %d\n", layout->n_collect);
	ft_printf("The player is at (%d, %d) ,", layout->player_x, layout->player_y);
	ft_printf("The exit is at (%d, %d) \n", layout->exit_x, layout->exit_y);
	ft_printf("The map is in this shape\n");
	while (layout->map[i])
		ft_printf("%s", layout->map[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:47:43 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/11 00:36:12 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_init(t_layout *layout)
{

	layout->mlx = mlx_init();
	layout->mlx_win = mlx_new_window(layout->mlx, layout->n_col * CS, \
	layout->n_row * CS, "My game");
	if (!layout->mlx_win)
		return (free(layout->mlx) , 1);
	ft_initial_map_to_screen(layout);
	ft_make_enemies(layout);
	mlx_hook(layout->mlx_win, 2, 1L<<0, ft_key_press, layout);
	mlx_hook(layout->mlx_win, 17, 0, on_destroy, layout);
	mlx_loop(layout->mlx);
	return (0);
}

t_enemy *ft_spawn_enemies(t_layout *layout)
{

	size_t	i;
	size_t	j;

	i = 0;
	while (layout->map[i])
	{
		j = 0;
		while (layout->map[i][j])
		{
			if (layout->map[i][j] == '0')
			{
				mlx_put_image_to_window(layout->mlx, layout->mlx_win, layout->all_imgs->wall->img, j * CS, i * CS);
				return(init_enemy(i, j));
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_enemy	*init_enemy(size_t i, size_t j)
{
	t_enemy	*enemy;

	enemy = malloc (sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->x = i;
	enemy->y = j;
	return (enemy);
}

void	ft_make_enemies(t_layout *layout)
{
	int	i;
	t_enemy	*enemy_list[MAX_ENEMIES];

	i = rand() % 10;
	while (i > 0 && layout->n_enemy < MAX_ENEMIES)
	{
		enemy_list[layout->n_enemy++] = ft_spawn_enemies(layout);
		i--;
	}
}

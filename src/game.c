/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:47:43 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/11 17:55:54 by plashkar         ###   ########.fr       */
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

void	ft_randomize_i_and_j(t_layout *layout, size_t *i, size_t *j)
{
	*i = rand() % (layout->n_row - 1);
	*j = rand() % (layout->n_col - 1);
}

t_enemy	*ft_spawn_enemies(t_layout *layout)
{

	size_t	i;
	size_t	j;

	ft_randomize_i_and_j(layout, &i, &j);
	while (layout->map[i] && i < layout->n_row - 1 && j < layout->n_col - 1)
	{
		while (layout->map[i][j])
		{
			if (layout->map[i][j] == '0')
			{
					mlx_put_image_to_window(layout->mlx, layout->mlx_win, layout->all_imgs->enemy->img, j * CS, i * CS);
					return (init_enemy(i, j));
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

	enemy = ft_calloc (1, sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->x = i;
	enemy->y = j;
	return (enemy);
}

void	ft_make_enemies(t_layout *layout)
{
	int	i;
	int	j;
	t_enemy	*new_enemy;

	i = rand() % 10;
	j = 0;
	while (i > 0 && j < MAX_ENEMIES)
	{
		new_enemy = ft_spawn_enemies(layout);
		if (new_enemy)
		{
			layout->enemies[j] = new_enemy;
			j++;
		}
		i--;
	}
	layout->n_enemy = j;
}

void	ft_hit_enemy_check(t_layout *layout)
{
	int	i;

	i = 0;
	while(i < layout->n_enemy)
	{
		if (layout->player_x == layout->enemies[i]->x && layout->player_y == layout->enemies[i]->y)
			on_destroy(layout);
		i++;
	}
}

int	ft_enemy_move(t_layout *layout)
{
	int	move_x;
	int	move_y;
	int new_x;
	int new_y;
	int	i;

	i = 0;
	while (layout->enemies[i])
	{
		move_x = (rand() % 3 - 1);
		move_y = (rand() % 3 - 1);
		if (move_x != 0 && move_y != 0)
			move_x = 0;
		new_x = layout->enemies[i]->x + move_x;
		new_y = layout->enemies[i]->y + move_y;
		if (layout->map[new_x][new_y] == '0')
		{
			mlx_put_image_to_window(layout->mlx, layout->mlx_win, \
		layout->all_imgs->background->img, layout->enemies[i]->y * CS, layout->enemies[i]->x * CS);
			mlx_put_image_to_window(layout->mlx, layout->mlx_win, layout->all_imgs->enemy->img, new_y * CS, new_x * CS);
			layout->enemies[i]->y = new_y;
			layout->enemies[i]->x = new_x;
		}

		i++;
	}
	return (0);
}

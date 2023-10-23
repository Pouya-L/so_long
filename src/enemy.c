/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:47:09 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/19 23:04:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_make_enemies(t_layout *layout)
{
	int		i;
	int		j;
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

t_enemy	*ft_spawn_enemies(t_layout *lay)
{
	size_t	i;
	size_t	j;

	i = rand() % (lay->n_row - 1);
	j = rand() % (lay->n_col - 1);
	while (lay->map[i] && i < lay->n_row - 1 && j < lay->n_col - 1)
	{
		while (lay->map[i][j])
		{
			if (lay->map[i][j] == '0')
			{
				mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
				lay->all_imgs->e_left->img, j * CS, i * CS);
				lay->map[i][j] = 'Z';
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
	enemy->is_dead = 0;
	return (enemy);
}

int	ft_enemy_move_gen(t_layout *l)
{
	int		mv_x;
	int		mv_y;
	int		i;

	i = 0;
	while (l->enemies[i])
	{
		if (!l->enemies[i]->is_dead)
		{
			mv_x = (rand() % 3 - 1);
			mv_y = (rand() % 3 - 1);
			if (mv_x != 0 && mv_y != 0)
				mv_x = 0;
			if (l->map[l->enemies[i]->x + mv_x][l->enemies[i]->y + mv_y] == '0')
			{
				l->map[l->enemies[i]->x][l->enemies[i]->y] = '0';
				l->map[l->enemies[i]->x + mv_x][l->enemies[i]->y + mv_y] = 'Z';
				ft_enemy_move(l, l->enemies[i], l->enemies[i]->x + mv_x, \
				l->enemies[i]->y + mv_y);
			}
		}
		i++;
	}
	ft_mlx_sync(l, 100);
	return (0);
}

void	ft_enemy_move(t_layout *lay, t_enemy *enemy, size_t new_x, size_t new_y)
{
	if (new_x == enemy->x - 1)
		enemy_move_up_anim(lay, enemy);
	if (new_x == enemy->x + 1)
		enemy_move_down_anim(lay, enemy);
	if (new_y == enemy->y - 1)
		enemy_move_left_anim(lay, enemy);
	if (new_y == enemy->y + 1)
		enemy_move_right_anim(lay, enemy);
	enemy->y = new_y;
	enemy->x = new_x;
}

// void	ft_enemy_move(t_layout *lay, t_enemy *enemy, size_t new_x, size_t new_y)
// {
// 	int	i;

// 	i = 0;
// 	while (lay->enemies[i] && !lay->enemies[i]->is_dead)
// 	{
// 		if (lay->enemies[i]->is_dead)
// 			i++;
// 		if (lay->enemies[i]->x != new_x && lay->enemies[i]->y != new_y)
// 		{
// 			if (new_x == enemy->x - 1)
// 				enemy_move_up_anim(lay, enemy);
// 			if (new_x == enemy->x + 1)
// 				enemy_move_down_anim(lay, enemy);
// 			if (new_y == enemy->y - 1)
// 				enemy_move_left_anim(lay, enemy);
// 			if (new_y == enemy->y + 1)
// 				enemy_move_right_anim(lay, enemy);
// 			enemy->y = new_y;
// 			enemy->x = new_x;
// 		}
// 		i++;
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:20:31 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 02:56:06 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_attack_right(t_layout *lay)
{
	int	i;

	i = 0;
	player_attack_right_anim(lay);
	if (lay->map[lay->player_x][lay->player_y + 1] == 'Z')
	{
		while (lay->enemies[i] && !lay->enemies[i]->is_dead)
		{
			if (lay->enemies[i]->x == lay->player_x && lay->enemies[i]->y == \
			lay->player_y + 1)
				lay->enemies[i]->is_dead = 1;
			i++;
		}
		enemy_death_anim_right(lay);
		lay->map[lay->player_x][lay->player_y + 1] = '0';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, ((lay->player_y + 1) * CS), \
		(lay->player_x * CS));
	}
}

void	player_attack_right_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_0->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_2->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_3->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_4->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_r_0->img, lay->player_y * CS, lay->player_x * CS);
}

void	player_attack_left(t_layout *lay)
{
	int	i;

	i = 0;
	player_attack_left_anim(lay);
	if (lay->map[lay->player_x][lay->player_y - 1] == 'Z')
	{
		while (lay->enemies[i] && !lay->enemies[i]->is_dead)
		{
			if (lay->enemies[i]->x == lay->player_x && lay->enemies[i]->y == \
			lay->player_y - 1)
				lay->enemies[i]->is_dead = 1;
			i++;
		}
		enemy_death_anim_left(lay);
		lay->map[lay->player_x][lay->player_y - 1] = '0';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, ((lay->player_y - 1) * CS), \
		(lay->player_x * CS));
	}
}

void	player_attack_left_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_0->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_2->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_3->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_4->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->atck_l_0->img, lay->player_y * CS, lay->player_x * CS);
}

void	enemy_death_anim_right(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, ((lay->player_y + 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up_1->img, ((lay->player_y + 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y + 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_1->img, ((lay->player_y + 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y + 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_2->img, ((lay->player_y + 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y + 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_3->img, ((lay->player_y + 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y + 1] = '0';
}

void	enemy_death_anim_left(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, ((lay->player_y - 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up_1->img, ((lay->player_y - 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y - 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_1->img, ((lay->player_y - 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y - 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_2->img, ((lay->player_y - 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
	lay->map[lay->player_x][lay->player_y - 1] = '0';
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_death_3->img, ((lay->player_y - 1) * CS), \
	(lay->player_x * CS));
	ft_mlx_sync(lay, 100000);
}

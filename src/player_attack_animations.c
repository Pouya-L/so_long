/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack_animations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:03:51 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 10:04:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

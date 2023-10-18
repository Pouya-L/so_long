/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:41:28 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/18 11:41:36 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move_up_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x - 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up->img, enemy->y * CS, \
	((double)enemy->x - 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x - 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up->img, enemy->y * CS, \
	((double)enemy->x - 1) * CS);
}

void	enemy_move_down_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x + 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_down->img, enemy->y * CS, \
	((double)enemy->x + 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x + 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_down->img, enemy->y * CS, \
	((double)enemy->x + 1) * CS);
}

void	enemy_move_right_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_0->img, (((double)enemy->y + 0.25) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_1->img, (((double)enemy->y + 0.5) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_2->img, (((double)enemy->y + 0.75) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_3->img, (((double)enemy->y + 1) * CS), \
	enemy->x * CS);
}

void	enemy_move_left_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, (((double)enemy->y - 0.25) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_1->img, (((double)enemy->y - 0.5) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_2->img, (((double)enemy->y - 0.75) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_3->img, (((double)enemy->y - 1) * CS), \
	enemy->x * CS);
}

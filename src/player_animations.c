/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:38:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/06 17:07:46 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_up_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_0->img, lay->player_y * CS, \
	((double)lay->player_x - 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_1->img, lay->player_y * CS, \
	((double)lay->player_x - 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_0->img, lay->player_y * CS, \
	((double)lay->player_x - 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_1->img, lay->player_y * CS, \
	((double)lay->player_x - 1) * CS);
}

void	player_move_down_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_1->img, lay->player_y * CS, \
	((double)lay->player_x + 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_0->img, lay->player_y * CS, \
	((double)lay->player_x + 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_1->img, lay->player_y * CS, \
	((double)lay->player_x + 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_0->img, lay->player_y * CS, \
	((double)lay->player_x + 1) * CS);
}

void	player_move_right_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right->img, (((double)lay->player_y + 0.25) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right_1->img, (((double)lay->player_y + 0.5) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right_2->img, (((double)lay->player_y + 0.75) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right->img, (((double)lay->player_y + 1) * CS), \
	lay->player_x * CS);
}

void	player_move_left_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left->img, (((double)lay->player_y - 0.25) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left_1->img, (((double)lay->player_y - 0.5) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left_2->img, (((double)lay->player_y - 0.75) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left->img, (((double)lay->player_y - 1) * CS), \
	lay->player_x * CS);
}

void	ft_player_death(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_4->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_5->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_6->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_7->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	ft_lose_msg(lay);
}

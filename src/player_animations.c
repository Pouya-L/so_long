/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:38:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/18 19:28:24 by plashkar         ###   ########.fr       */
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
	lay->all_imgs->death_0->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_2->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_3->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
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

void	ft_lose_msg(t_layout *layout)
{
	layout->end_mlx = mlx_init();
	layout->end_win = mlx_new_window(layout->end_mlx, 1024, \
	576, "END");
	mlx_put_image_to_window(layout->end_mlx, layout->end_win, \
	layout->all_imgs->you_lose->img, 0, 0);
	ft_mlx_sync_end(layout, 1000000);
	mlx_destroy_window(layout->end_mlx, layout->end_win);
	mlx_destroy_display(layout->end_mlx);
	free(layout->end_mlx);
	on_destroy(layout);
}

void	ft_win_msg(t_layout *layout)
{
	layout->end_win = mlx_new_window(layout->mlx, 612, \
	612, "END");
	mlx_put_image_to_window(layout->end_mlx, layout->end_win, \
	layout->all_imgs->you_win->img, 0, 0);
	ft_mlx_sync_end(layout, 100000);
	mlx_destroy_window(layout->end_mlx, layout->end_win);
	mlx_destroy_display(layout->end_mlx);
	free(layout->end_mlx);
	on_destroy(layout);
}

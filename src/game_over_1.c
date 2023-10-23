/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 11:41:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Animates the death scene
void	death_scene_render_0(t_layout *lay)
{
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_0->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_1->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_2->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_3->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_4->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_5->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_6->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_7->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	death_scene_rende_1(lay);
}

//Animates the death scene
void	death_scene_rende_1(t_layout *lay)
{
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_8->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_9->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_10->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_11->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_12->img, 0, 0);
	ft_mlx_sync_end(lay, 100000);
	mlx_put_image_to_window(lay->end_mlx, lay->end_win, \
	lay->game_over->lf_13->img, 0, 0);
	ft_mlx_sync_end(lay, 500000);
}

//Destroy and frees the death scene images and their pointers
void	destroy_game_over_0(t_layout *lay)
{
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_0->img);
	free(lay->game_over->lf_0);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_1->img);
	free(lay->game_over->lf_1);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_2->img);
	free(lay->game_over->lf_2);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_3->img);
	free(lay->game_over->lf_3);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_4->img);
	free(lay->game_over->lf_4);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_5->img);
	free(lay->game_over->lf_5);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_6->img);
	free(lay->game_over->lf_6);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_7->img);
	free(lay->game_over->lf_7);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_8->img);
	free(lay->game_over->lf_8);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_9->img);
	free(lay->game_over->lf_9);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_10->img);
	free(lay->game_over->lf_10);
	destroy_game_over_1(lay);
}

//Destroy and frees the death scene images and their pointers
void	destroy_game_over_1(t_layout *lay)
{
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_11->img);
	free(lay->game_over->lf_11);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_12->img);
	free(lay->game_over->lf_12);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_13->img);
	free(lay->game_over->lf_13);
	mlx_destroy_image(lay->end_mlx, lay->game_over->win_0->img);
	free(lay->game_over->win_0);
	free(lay->game_over);
	mlx_destroy_window(lay->end_mlx, lay->end_win);
	mlx_destroy_display(lay->end_mlx);
	free(lay->end_mlx);
	exit(0);
}

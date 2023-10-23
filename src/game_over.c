/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:50:51 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 02:54:32 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lose_msg(t_layout *layout)
{
	layout->flag_game_over = 1;
	on_destroy(layout);
	layout->end_mlx = mlx_init();
	layout->end_win = mlx_new_window(layout->end_mlx, 500, \
	256, "END");
	layout->game_over = death_scene_make_all_images(layout);
	death_scene_render_0(layout);
	destroy_game_over_0(layout);
}

void	ft_win_msg(t_layout *layout)
{
	layout->flag_game_over = 1;
	on_destroy(layout);
	layout->end_win = mlx_new_window(layout->mlx, 612, \
	612, "END");
	mlx_destroy_window(layout->end_mlx, layout->end_win);
	mlx_destroy_display(layout->end_mlx);
	free(layout->end_mlx);
}

t_game_over	*death_scene_make_all_images(t_layout *lay)
{
	t_game_over	*game_over;

	game_over = malloc(sizeof(t_game_over));
	if (!game_over)
		return (0);
	game_over->lf_0 = ft_gameover_xpm("images/Lose_0.xpm", lay);
	game_over->lf_1 = ft_gameover_xpm("images/Lose_1.xpm", lay);
	game_over->lf_2 = ft_gameover_xpm("images/Lose_2.xpm", lay);
	game_over->lf_3 = ft_gameover_xpm("images/Lose_3.xpm", lay);
	game_over->lf_4 = ft_gameover_xpm("images/Lose_4.xpm", lay);
	game_over->lf_5 = ft_gameover_xpm("images/Lose_5.xpm", lay);
	game_over->lf_6 = ft_gameover_xpm("images/Lose_6.xpm", lay);
	game_over->lf_7 = ft_gameover_xpm("images/Lose_7.xpm", lay);
	game_over->lf_8 = ft_gameover_xpm("images/Lose_8.xpm", lay);
	game_over->lf_9 = ft_gameover_xpm("images/Lose_9.xpm", lay);
	game_over->lf_10 = ft_gameover_xpm("images/Lose_10.xpm", lay);
	game_over->lf_11 = ft_gameover_xpm("images/Lose_11.xpm", lay);
	game_over->lf_12 = ft_gameover_xpm("images/Lose_12.xpm", lay);
	game_over->lf_13 = ft_gameover_xpm("images/Lose_13.xpm", lay);
	return (game_over);
}

t_img	*ft_gameover_xpm(char *path, t_layout *lay)
{
	t_img	*image;
	int		width;
	int		height;

	image = malloc(sizeof(t_img));
	if (!image)
		return (0);
	image->img = mlx_xpm_file_to_image(lay->end_mlx, path, &width, &height);
	image->addr = mlx_get_data_addr(image->img, \
	&(image->bits_per_pixel), &(image->line_length), &(image->endian));
	return (image);
}

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

void	destroy_game_over_1(t_layout *lay)
{
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_11->img);
	free(lay->game_over->lf_11);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_12->img);
	free(lay->game_over->lf_12);
	mlx_destroy_image(lay->end_mlx, lay->game_over->lf_13->img);
	free(lay->game_over->lf_13);
	free(lay->game_over);
	mlx_destroy_window(lay->end_mlx, lay->end_win);
	mlx_destroy_display(lay->end_mlx);
	free(lay->end_mlx);
	exit(0);
}

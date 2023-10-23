/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:50:51 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 11:49:15 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Destroys the game windows, make a new window and runs the death scene video
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

//Destroys the game windows, make a new window and runs the win scene
void	ft_win_msg(t_layout *layout)
{
	layout->flag_game_over = 1;
	on_destroy(layout);
	layout->end_mlx = mlx_init();
	layout->end_win = mlx_new_window(layout->end_mlx, 612, \
	612, "END");
	layout->game_over = death_scene_make_all_images(layout);
	mlx_put_image_to_window(layout->end_mlx, layout->end_win, \
	layout->game_over->win_0->img, 0, 0);
	ft_mlx_sync_end(layout, 1000000);
	destroy_game_over_0(layout);
}

//Makes the poniters to frames for the death scence
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
	game_over->win_0 = ft_gameover_xpm("images/win.xpm", lay);
	return (game_over);
}

//Makes a frame for the death scence
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 18:56:29 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->background->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_up->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_down->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_right->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_left->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->collect->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->wall->img);
	mlx_destroy_image(layout->mlx, layout->all_imgs->exit->img);
	// mlx_destroy_image(layout->mlx, layout->all_imgs->enemy->img);
	mlx_destroy_window(layout->mlx, layout->mlx_win);
	mlx_destroy_display(layout->mlx);
	free_2d_array(layout->map);
	free(layout->mlx);
	exit(0);
}





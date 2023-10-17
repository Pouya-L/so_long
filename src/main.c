/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:56:33 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/17 18:46:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_layout	layout;

	srand(time(NULL));
	ft_check_params(argc, argv);
	ft_memset(&layout, 0, sizeof(layout));
	ft_map_allocate(&layout, argv);
	ft_player_and_exit_coordinates(&layout);
		print_map_details(&layout);
	ft_map_validations(&layout);
	game_init(&layout);
	return (0);
}
void ft_player_death(t_layout *lay)
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
	on_destroy(lay);
}

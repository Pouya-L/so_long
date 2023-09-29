/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:38:58 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/29 15:26:07 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data		img;

	img.mlx = mlx_init();
	if (!img.mlx)
		return (1);
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "Hello world!");
	if (!img.mlx_win)
		return (free(img.mlx), 1);

	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);

	shape_info diagonal_line;
	diagonal_line.x = 100;
	diagonal_line.y = 100;
	diagonal_line.size = 50;
	diagonal_line.color = 0x00FFAA00;
	my_mlx_diagonal_line_put(&img, diagonal_line);

	shape_info square;
	square.x = 50;
	square.y = 50;
	square.size = 50;
	square.color = 0x00FF0000;
	my_mlx_square_put(&img, square);

	shape_info horizental_line;
	horizental_line.x = 150;
	horizental_line.y = 150;
	horizental_line.width = 50;
	horizental_line.color = 0x00FF0000;
	my_mlx_horizental_line(&img, horizental_line);

	shape_info vertical_line;
	vertical_line.x = 200;
	vertical_line.y = 150;
	vertical_line.height = 50;
	vertical_line.color = 0x00FF0000;
	my_mlx_vertical_line(&img, vertical_line);

	shape_info circle;
	circle.x = 300;
	circle.y = 300;
	circle.size = 100;
	circle.color = 0x00FF0000;
	circle.angle = 0;
	my_mlx_circle_put(&img, circle);

	shape_info circle2;
	circle2.x = 600;
	circle2.y = 300;
	circle2.size = 100;
	circle2.color = 0x00FF0000;
	circle2.angle = 0;
	my_mlx_circle_put(&img, circle2);

	shape_info circlep;
	circlep.x = 350;
	circlep.y = 300;
	circlep.size = 30;
	circlep.color = 0x00FF0000;
	circlep.angle = 0;
	my_mlx_circle_put(&img, circlep);

	shape_info circle2p;
	circle2p.x = 650;
	circle2p.y = 300;
	circle2p.size = 30;
	circle2p.color = 0x00FF0000;
	circle2p.angle = 0;
	my_mlx_circle_put(&img, circle2p);

	shape_info horizental_line2;
	horizental_line2.x = 425;
	horizental_line2.y = 450;
	horizental_line2.width = 50;
	horizental_line2.color = 0x00FF0000;
	my_mlx_horizental_line(&img, horizental_line2);

	shape_info half_circle;
	half_circle.x = 450;
	half_circle.y = 500;
	half_circle.size = 50;
	half_circle.color = 0x00FF0000;
	half_circle.angle = 2;
	my_mlx_half_circle(&img, half_circle);

	shape_info circle_3;
	circle_3.x = 650;
	circle_3.y = 600;
	circle_3.size = 30;
	circle_3.color = 0x00FF0000;
	circle_3.angle = M_PI;
	my_mlx_circle_put(&img, circle_3);

	shape_info rainbow_sqaure;
	rainbow_sqaure.x = 0;
	rainbow_sqaure.y = 500;
	rainbow_sqaure.size = 200;
	my_mlx_rainbow_square(&img, rainbow_sqaure);

	shape_info square2;
	square2.x = 50;
	square2.y = 150;
	square2.size = 60;
	square2.color = 0x7751A0;
	double shading_factor = 0.7;
	square2.color = add_shade(shading_factor , square2.color);
	my_mlx_square_put(&img, square2);

	shape_info square3;
	square3.x = 50;
	square3.y = 250;
	square3.size = 60;
	square3.color = 0x7751A0;
	square3.color = get_opposite_color(square3.color);
	my_mlx_square_put(&img, square3);

	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);

	mlx_hook(img.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &img);

	mlx_hook(img.mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &img);

	mlx_loop(img.mlx);
	// mlx_destroy_image(data.mlx, img.img);
	// mlx_destroy_window(data.mlx, data.mlx_win);
	// mlx_destroy_display(data.mlx);
	// free(data.mlx);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 	return (1);
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
// 	free(mlx_ptr);
// 	return (0);
// }

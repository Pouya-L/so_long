/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:38:58 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/25 16:53:37 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	shape_info diagonal_line;
	diagonal_line.x = 100;
	diagonal_line.y = 100;
	diagonal_line.size = 50;
	diagonal_line.color = 0x00FF0000;
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
	horizental_line2.x = 450;
	horizental_line2.y = 450;
	horizental_line2.width = 50;
	horizental_line2.color = 0x00FF0000;
	my_mlx_horizental_line(&img, horizental_line2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
// }

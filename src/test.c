/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:27:05 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/25 16:44:42 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int offset = (y * line_length + x * (bits_per_pixel / 8));

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_diagonal_line_put(t_data *data, shape_info diagonal_line)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < diagonal_line.size)
	{
		dst = data->addr + ((diagonal_line.y + i) * data->line_length + \
		(diagonal_line.x + i) * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = diagonal_line.color;
		i++;
	}
}

void	my_mlx_horizental_line(t_data *data, shape_info horizental_line)
{
	int	i;

	i = 0;
	while (i < horizental_line.width)
	{
		my_mlx_pixel_put(data, horizental_line.x + i, horizental_line.y, \
		horizental_line.color);
		i++;
	}
}

void	my_mlx_vertical_line(t_data *data, shape_info vertical_line)
{
	int	i;

	i = 0;
	while (i < vertical_line.height)
	{
		my_mlx_pixel_put(data, vertical_line.x, vertical_line.y + i, \
		vertical_line.color);
		i++;
	}
}

void	my_mlx_square_put(t_data *data, shape_info square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < square.size)
	{
		my_mlx_pixel_put(data, square.x + i, square.y + j, square.color);
		j = 0;
		while (j < square.size)
		{
			my_mlx_pixel_put(data, square.x + i, square.y + j, square.color);
			j++;
		}
		i++;
	}
}

void	my_mlx_circle_put(t_data *data, shape_info circle)
{
	int x;
	int y;

	while (circle.angle <= 2 * M_PI)
	{
		x = circle.x + (int)(cosf(circle.angle) * circle.size);
		y = circle.y + (int)(sinf(circle.angle) * circle.size);
		my_mlx_pixel_put(data, x, y, circle.color);
		circle.angle += (M_PI / 180.0);
	}
}

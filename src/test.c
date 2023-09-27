/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:27:05 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/27 15:11:55 by plashkar         ###   ########.fr       */
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

// void	my_mlx_square_put(t_data *data, shape_info square)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < square.size)
// 	{
// 		my_mlx_pixel_put(data, square.x + i, square.y + j, square.color);
// 		j = 0;
// 		while (j < square.size)
// 		{
// 			my_mlx_pixel_put(data, square.x + i, square.y + j, square.color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	my_mlx_square_put(t_data *data, shape_info square)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < square.size)
	{
		while (j < square.size)
		{
			my_mlx_pixel_put(data, square.x + i, square.y + j, square.color);
			j++;
		}
		j = 0;
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

void	my_mlx_half_circle(t_data *data, shape_info half_circle)
{
	int x;
	int y;

	while (half_circle.angle <= M_PI)
	{
		x = half_circle.x + (int)(cosf(half_circle.angle) * half_circle.size);
		y = half_circle.y + (int)(sinf(half_circle.angle) * half_circle.size);
		my_mlx_pixel_put(data, x ,y, half_circle.color);
		half_circle.angle += (M_PI / 180.0);
	}
}

void	my_mlx_rainbow_square(t_data *data, shape_info rainbow_square)
{
	int			i;
	int			j;
	uint32_t	rgb_color;

	i = 0;
	j = 0;
	while (i < rainbow_square.size)
	{
		rgb_color = get_rainbow_color(i, rainbow_square.size);

		while (j < rainbow_square.size)
		{
			my_mlx_pixel_put(data, rainbow_square.x + i, rainbow_square.y + j, rgb_color);
			j++;
		}

		j = 0;
		i++;
	}
}

uint32_t	get_wtf_color(int position, int size)
{
	int red = 255 * (position * 2) / size;
	int green = 255 - (255 * position) / size;
	int blue = 255 - (255 * position) / size;

	return ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
}

uint32_t	get_rainbow_color(int position, int size)
{
	double	hue;
	int		red;
	int		green;
	int		blue;
	int		alpha;

	alpha = 120;
	hue = (double)position / size * 360.0;

	if (hue >= 0.0 && hue < 60.0)
	{
		red = 255;
		green = (int)(255 * (hue / 60.0));
		blue = 0;
	}
	else if (hue >= 60.0 && hue < 120.0)
	{
		red = 255 - (int)(255 * ((hue - 60.0) / 60.0));
		green = 255;
		blue = 0;
	}
	else if (hue >= 120.0 && hue < 180.0)
	{
		red = 0;
		green = 255;
		blue = (int)(255 * (hue - 120.0) / 60.0);
	}
	else if (hue >= 180.0 && hue < 240.0)
	{
		red = 0;
		green = 255 - (int)(255 * ((hue - 180.0) / 60.0));
		blue = 255;
	}
	else if (hue >= 240.0 && hue < 300.0)
	{
		red = (int)(255 * ((hue - 240.0) / 60.0));
		green = 0;
		blue = 255;
	}
	else
	{
		red = 255;
		green = 0;
		blue = 255 - (int)(255 * ((hue - 300.0) / 60.0));
	}
	return (rgba_to_int(alpha, red, green, blue));
}

uint32_t	rgba_to_int(int t, int r, int g, int b)
{
	int	color;

	color = ((uint32_t)t << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;

	return (color);
}

//Adds shade to the color, shade_factor is between 0.0 and 1.0
//0.0 means it's completely dark
//1.0 means it's completely light
uint32_t	add_shade(double shading_factor, uint32_t color)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;
	uint32_t shaded_color;

	alpha = (color >> 24) & 0xFF;
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;

	if (shading_factor > 1.0)
		shading_factor = 1.0;
	else if (shading_factor < 0.0)
		shading_factor = 0.0;
	red = (int)(red * shading_factor);
	green = (int)(green * shading_factor);
	blue = (int)(blue * shading_factor);
	shaded_color = ((uint32_t)alpha << 24) | ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
	return (shaded_color);
}

uint32_t	get_opposite_color(uint32_t color)
{
	int	alpha;
	int anti_red;
	int anti_green;
	int anti_blue;
	uint32_t opposite_color;

	alpha = (color >> 24) & 0xFF;
	anti_red = 255 - ((color >> 16) & 0xFF);
	anti_green = 255 - ((color >> 8) & 0xFF);
	anti_blue = 255 - (color & 0xFF);
	opposite_color = ((uint32_t)alpha << 24) | ((uint32_t)anti_red << 16) | ((uint32_t)anti_green << 8) | (uint32_t)anti_blue;
	return (opposite_color);
}

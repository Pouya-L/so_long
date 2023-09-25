/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:50:07 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/25 16:42:32 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct shape_info {
	int	x;
	int	y;
	int	color;
	int	size;
	int	height;
	int	width;
	double	angle;
}	shape_info;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_horizental_line(t_data *data, shape_info horizental_line);
void	my_mlx_vertical_line(t_data *data, shape_info vertical_line);
void	my_mlx_square_put(t_data *data, shape_info square);
void	my_mlx_diagonal_line_put(t_data *data, shape_info diagonal_line);
void	my_mlx_circle_put(t_data *data, shape_info circle);

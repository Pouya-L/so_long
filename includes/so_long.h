/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:50:07 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/27 17:46:20 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct shape_info {
	int			x;
	int			y;
	uint32_t	color;
	int			size;
	int			height;
	int			width;
	double		angle;
}	shape_info;

//shapes and colors
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		my_mlx_horizental_line(t_data *data, shape_info horizental_line);
void		my_mlx_vertical_line(t_data *data, shape_info vertical_line);
void		my_mlx_square_put(t_data *data, shape_info square);
void		my_mlx_diagonal_line_put(t_data *data, shape_info diagonal_line);
void		my_mlx_circle_put(t_data *data, shape_info circle);
void		my_mlx_half_circle(t_data *data, shape_info half_circle);
void		my_mlx_rainbow_square(t_data *data, shape_info rainbow_square);
uint32_t	get_wtf_color(int position, int size);
uint32_t	get_rainbow_color(int position, int size);
uint32_t	rgba_to_int(int t, int r, int g, int b);
uint32_t	add_shade(double shading_factor, uint32_t color);
uint32_t	get_opposite_color(uint32_t color);

//error checks and free functions
int	on_destroy(t_data *data);

//keyboard and mouse management
int	on_keypress(int keysymb, t_data *img);



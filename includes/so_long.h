/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:50:07 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/09 17:17:44 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdbool.h>

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

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

typedef struct s_layout {
	size_t	n_row;
	size_t	n_col;
	int	n_exit;
	size_t	exit_x;
	size_t	exit_y;
	int	exit_path_check;
	int	n_player;
	size_t	player_x;
	size_t	player_y;
	int	n_enemy;
	int	n_collect;
	int	collect_path_check;
	int	inv_char;
	char	**map;
}	t_layout;

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

//struct initiators
t_layout	ft_memset_layout();

void	ft_map_validations(t_layout *layout);

int	ft_top_and_bottom_border(t_layout *layout);
int	left_and_right_border(t_layout *layout);

void	ft_map_allocate(t_layout *layout, char **argv);
void	ft_layout_struct_updater(t_layout *layout);

int	ft_count_lines(char **argv);

void	ft_check_params(int argc, char **argv);

int	error_msg_and_free(char *msg, char **map);

void	print_map_details(t_layout *layout);

bool	ft_path_exists(size_t start_row, size_t start_col, t_layout *layout);

void	ft_player_and_exit_coordinates(t_layout *layout);

int	map_copy_and_check(t_layout *layout);

void	ft_check_path(t_layout *layout, size_t x, size_t y, char **map_copy);

void	free_2D_array(char **map_copy);

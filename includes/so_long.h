/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:50:07 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 18:27:45 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define CS 140

enum {
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	DIRK_UP = 65362,
	DIRK_LEFT = 65361,
	DIRK_DOWN = 65364,
	DIRK_RIGHT = 65363,
	K_ESC = 65307,
};

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_all_img {
	t_img	*background;
	t_img	*player_up;
	t_img	*player_down;
	t_img	*player_right;
	t_img	*player_left;
	t_img	*collect;
	t_img	*wall;
	t_img	*exit;
	t_img	*enemy;
}	t_all_img;

typedef struct s_layout {
	size_t		n_row;
	size_t		n_col;
	int			n_exit;
	size_t		exit_x;
	size_t		exit_y;
	int			exit_path_check;
	int			n_player;
	size_t		player_x;
	size_t		player_y;
	int			n_enemy;
	int			n_collect;
	int			collect_path_check;
	int			inv_char;
	char		**map;
	int			move_cnt;
	void		*mlx;
	void		*mlx_win;
	t_all_img	*all_imgs;
}	t_layout;

// typedef struct shape_info {
// 	int			x;
// 	int			y;
// 	uint32_t	color;
// 	int			size;
// 	int			height;
// 	int			width;
// 	double		angle;
// }	t_shape_info;

// //shapes and colors
// void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void		my_mlx_horizental_line(t_data *data, shape_info horizental_line);
// void		my_mlx_vertical_line(t_data *data, shape_info vertical_line);
// void		my_mlx_square_put(t_data *data, shape_info square);
// void		my_mlx_diagonal_line_put(t_data *data, shape_info diagonal_line);
// void		my_mlx_circle_put(t_data *data, shape_info circle);
// void		my_mlx_half_circle(t_data *data, shape_info half_circle);
// void		my_mlx_rainbow_square(t_data *data, shape_info rainbow_square);
// uint32_t	get_wtf_color(int position, int size);
// uint32_t	get_rainbow_color(int position, int size);
// uint32_t	rgba_to_int(int t, int r, int g, int b);
// uint32_t	add_shade(double shading_factor, uint32_t color);
// uint32_t	get_opposite_color(uint32_t color);

//error checks and free functions
int	on_destroy(t_layout *layout);
int			error_msg_and_free(char *msg, char **map);
void		free_2d_array(char **map_copy);

//keyboard and mouse management
int	ft_key_press(int keysymb, t_layout *layout);

//Map check and validation
void		ft_map_validations(t_layout *layout);
int			ft_top_and_bottom_border(t_layout *layout);
int			left_and_right_border(t_layout *layout);
void		ft_layout_struct_updater(t_layout *layout);
void		ft_check_params(int argc, char **argv);
void		print_map_details(t_layout *layout);
void		ft_player_and_exit_coordinates(t_layout *layout);
int			map_copy_and_check(t_layout *layout);
void		ft_check_path(t_layout *layout, size_t x, size_t y, char **map_cpy);

//Map read and creation
int			ft_count_lines(char **argv);
void		ft_map_allocate(t_layout *layout, char **argv);

int	game_init(t_layout *layout);

void		ft_initial_map_to_screen(t_layout *layout);
void		ft_map_characters(t_layout *layout, t_all_img *all_imgs ,int i, int j);
t_all_img	*ft_make_all_images(t_layout *layout);
t_img		*ft_make_img_xpm(char *path, t_layout *layout);

void	player_move_up(t_layout *lay);
void	player_move_down(t_layout *lay);
void	player_move_right(t_layout *lay);
void	player_move_left(t_layout *lay);

void	ft_put_move_number(t_layout *layout);


#endif

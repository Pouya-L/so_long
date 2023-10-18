/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:50:07 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/18 19:14:14 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <time.h>
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

# define CS 100
# define MAX_ENEMIES 10
# define KONAMI_CODE "UUDDLRLRBASS"

enum {
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_C = 99,
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
	t_img	*p_up_0;
	t_img	*p_up_1;
	t_img	*p_down_0;
	t_img	*p_down_1;
	t_img	*p_right;
	t_img	*p_right_1;
	t_img	*p_right_2;
	t_img	*p_left;
	t_img	*p_left_1;
	t_img	*p_left_2;
	t_img	*collect;
	t_img	*wall;
	t_img	*exit;
	t_img	*e_left;
	t_img	*e_up;
	t_img	*e_down;
	t_img	*e_left_1;
	t_img	*e_left_2;
	t_img	*e_left_3;
	t_img	*e_right_0;
	t_img	*e_right_1;
	t_img	*e_right_2;
	t_img	*e_right_3;
	t_img	*death_0;
	t_img	*death_1;
	t_img	*death_2;
	t_img	*death_3;
	t_img	*death_4;
	t_img	*death_5;
	t_img	*death_6;
	t_img	*death_7;
	t_img	*you_lose;
	t_img	*you_win;
}	t_all_img;

typedef struct s_enemy {
	size_t		x;
	size_t		y;
}	t_enemy;

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
	t_enemy		*enemies[MAX_ENEMIES];
	int			n_collect;
	int			collect_path_check;
	int			inv_char;
	char		**map;
	int			move_cnt;
	void		*mlx;
	void		*mlx_win;
	void		*end_mlx;
	void		*end_win;
	t_all_img	*all_imgs;
}	t_layout;

//utils and free functions
int			on_destroy(t_layout *layout);
void		on_destroy_1(t_layout *layout);
void		on_destroy_2(t_layout *layout);
int			error_msg_and_free(char *msg, char **map);
void		free_2d_array(char **map_copy);
void		ft_mlx_sync(t_layout *layout, int time);
void		ft_mlx_sync_end(t_layout *layout, int time);

//keyboard and mouse management
int			ft_key_press(int keysymb, t_layout *layout);

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

//Game initialization
int			game_init(t_layout *layout);
void		ft_initial_map_to_screen(t_layout *layout);
void		ft_map_characters(t_layout *lay, t_all_img *all_imgs, int i, int j);
void		ft_hit_enemy_check(t_layout *layout);

//Image functions
t_all_img	*ft_make_all_images(t_layout *layout);
void		ft_make_all_images_1(t_layout *layout, t_all_img *all_imgs);
t_img		*ft_make_img_xpm(char *path, t_layout *layout);
void		ft_put_move_number(t_layout *layout);
void		ft_lose_msg(t_layout *layout);
void		ft_win_msg(t_layout *layout);

//Player move functions
void		player_move_up(t_layout *lay);
void		player_move_down(t_layout *lay);
void		player_move_right(t_layout *lay);
void		player_move_left(t_layout *lay);

//Enemy spawn and move functions
t_enemy		*init_enemy(size_t i, size_t j);
t_enemy		*ft_spawn_enemies(t_layout *layout);
void		ft_make_enemies(t_layout *layout);
int			ft_enemy_move_gen(t_layout *layout);
void		ft_enemy_move(t_layout *lay, t_enemy *enemy, size_t new_x, \
			size_t new_y);

//Animations
void		player_move_up_anim(t_layout *lay);
void		player_move_down_anim(t_layout *lay);
void		player_move_right_anim(t_layout *lay);
void		player_move_left_anim(t_layout *lay);
void		enemy_move_up_anim(t_layout *lay, t_enemy *enemy);
void		enemy_move_down_anim(t_layout *lay, t_enemy *enemy);
void		enemy_move_right_anim(t_layout *lay, t_enemy *enemy);
void		enemy_move_left_anim(t_layout *lay, t_enemy *enemy);
void		ft_player_death(t_layout *lay);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:56:33 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 18:40:40 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_layout	layout;

	ft_check_params(argc, argv);
	ft_memset(&layout, 0, sizeof(layout));
	ft_map_allocate(&layout, argv);
	ft_player_and_exit_coordinates(&layout);
		print_map_details(&layout);
	ft_map_validations(&layout);
	game_init(&layout);
	return (0);
}

int	game_init(t_layout *layout)
{
	layout->mlx = mlx_init();
	layout->mlx_win = mlx_new_window(layout->mlx, layout->n_col * CS, \
	layout->n_row * CS, "My game");
	if (!layout->mlx_win)
		return (free(layout->mlx) , 1);


	ft_initial_map_to_screen(layout);
	mlx_hook(layout->mlx_win, 2, 1L<<0, ft_key_press, layout);
	mlx_hook(layout->mlx_win, 17, 0, on_destroy, layout);
	mlx_loop(layout->mlx);
	return (0);
}

int	ft_key_press(int keysymb, t_layout *layout)
{
	ft_player_and_exit_coordinates(layout);
		ft_printf("Pressed key: %d\n", keysymb);
	if (keysymb == K_ESC)
		on_destroy(layout);
	if (keysymb == KEY_W || keysymb == DIRK_UP)
		player_move_up(layout);
	if (keysymb == KEY_A || keysymb == DIRK_LEFT)
		player_move_left(layout);
	if (keysymb == KEY_S || keysymb == DIRK_DOWN)
		player_move_down(layout);
	if (keysymb == KEY_D ||keysymb == DIRK_RIGHT)
		player_move_right(layout);

			ft_printf("\nThe move count is %d \n", layout->move_cnt);


	return (0);
}

void	player_move_up(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x - 1][lay->player_y];
	if (lay->map[lay->player_x - 1][lay->player_y] == 'E' && lay->n_collect == 0)
		on_destroy(lay);
	else if (lay->map[lay->player_x - 1][lay->player_y] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_up->img, lay->player_y * CS, (lay->player_x - 1) * CS);
		ft_put_move_number(lay);
	}
	else
	{
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_up->img, lay->player_y * CS, lay->player_x * CS);
	}
}

void	player_move_down(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x + 1][lay->player_y];

	if (lay->map[lay->player_x + 1][lay->player_y] == 'E' && lay->n_collect == 0)
		on_destroy(lay);
	else if (lay->map[lay->player_x + 1][lay->player_y] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_down->img, lay->player_y * CS, (lay->player_x + 1) * CS);
		ft_put_move_number(lay);
	}
	else
	{
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_down->img, lay->player_y * CS, lay->player_x * CS);
	}
}

void	player_move_right(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x][lay->player_y + 1];

	if (lay->map[lay->player_x][lay->player_y + 1] == 'E' && lay->n_collect == 0)
		on_destroy(lay);
	else if (lay->map[lay->player_x][lay->player_y + 1] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_right->img, (lay->player_y + 1) * CS, lay->player_x * CS);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_right->img, lay->player_y * CS, lay->player_x * CS);
}

void	player_move_left(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x][lay->player_y - 1];

	if (lay->map[lay->player_x][lay->player_y - 1] == 'E' && lay->n_collect == 0)
		on_destroy(lay);
	else if (lay->map[lay->player_x][lay->player_y - 1] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_left->img, (lay->player_y - 1) * CS, lay->player_x * CS);
		ft_put_move_number(lay);
	}
	else
	{
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_left->img, lay->player_y * CS, lay->player_x * CS);
	}
}

void	ft_initial_map_to_screen(t_layout *layout)
{
	int	i;
	int	j;

	i = 0;
	layout->all_imgs = ft_make_all_images(layout);
	while (layout->map[i])
	{
		j = 0;
		while (layout->map[i][j])
		{
			ft_map_characters(layout, layout->all_imgs, i, j);
			j++;
		}
		i++;
	}
}

void	ft_map_characters(t_layout *layout, t_all_img *all_imgs ,int i, int j)
{
	if (layout->map[i][j] == '1')
		mlx_put_image_to_window(layout->mlx, layout->mlx_win, all_imgs->wall->img, j * CS, i * CS);
	else if (layout->map[i][j] == '0')
		mlx_put_image_to_window(layout->mlx, layout->mlx_win, all_imgs->background->img, j * CS, i * CS);
	else if (layout->map[i][j] == 'P')
		mlx_put_image_to_window(layout->mlx, layout->mlx_win, all_imgs->player_right->img, j * CS, i * CS);
	else if (layout->map[i][j] == 'E')
		mlx_put_image_to_window(layout->mlx, layout->mlx_win, all_imgs->exit->img, j * CS, i * CS);
	else if (layout->map[i][j] == 'C')
		mlx_put_image_to_window(layout->mlx, layout->mlx_win, all_imgs->collect->img, j * CS, i * CS);
}

//DO NOT FORGET TO FREE < STATUS NOT FREED >
t_all_img	*ft_make_all_images(t_layout *layout)
{
	t_all_img	*all_imgs;

	all_imgs = malloc(sizeof(t_all_img));
	if (!all_imgs)
		return (0);
	all_imgs->background = ft_make_img_xpm("images/background.xpm", layout);
	all_imgs->player_up = ft_make_img_xpm("images/player_up.xpm", layout);
	all_imgs->player_down = ft_make_img_xpm("images/player_down.xpm", layout);
	all_imgs->player_right = ft_make_img_xpm("images/player_right.xpm", layout);
	all_imgs->player_left = ft_make_img_xpm("images/player_left.xpm", layout);
	all_imgs->collect = ft_make_img_xpm("images/collect.xpm", layout);
	all_imgs->wall = ft_make_img_xpm("images/wall.xpm", layout);
	all_imgs->exit = ft_make_img_xpm("images/exit.xpm", layout);
	//all_imgs->enemy = ft_make_img_xpm("images/enemy.xpm", layout);
	return (all_imgs);
}

//DO NOT FORGET TO FREE < STATUS NOT FREED >
t_img	*ft_make_img_xpm(char *path, t_layout *layout)
{
	t_img	*image;
	int		width;
	int		height;

	image = malloc(sizeof(t_img));
	if (!image)
		return (0);
	image->img = mlx_xpm_file_to_image(layout->mlx, path, &width, &height);
	image->addr = mlx_get_data_addr(image->img, \
	&(image->bits_per_pixel), &(image->line_length), &(image->endian));
	return(image);
}

void	ft_put_move_number(t_layout *layout)
{
	char	*moves;

	moves = ft_itoa(layout->move_cnt++);
	mlx_put_image_to_window(layout->mlx, layout->mlx_win, layout->all_imgs->wall->img, 0 * CS, 0 * CS);
	mlx_string_put(layout->mlx, layout->mlx_win, 10, 20, 0xffffffff, moves);
	free(moves);
}

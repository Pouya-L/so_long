/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:53:04 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/11 09:58:51 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	all_imgs->enemy = ft_make_img_xpm("images/enemy.xpm", layout);
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

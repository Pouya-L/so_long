/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:53:04 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 02:56:20 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_map_characters(t_layout *lay, t_all_img *all_imgs, int i, int j)
{
	if (lay->map[i][j] == '1')
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		all_imgs->wall->img, j * CS, i * CS);
	else if (lay->map[i][j] == '0')
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		all_imgs->background->img, j * CS, i * CS);
	else if (lay->map[i][j] == 'P')
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		all_imgs->p_right->img, j * CS, i * CS);
	else if (lay->map[i][j] == 'E')
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		all_imgs->exit->img, j * CS, i * CS);
	else if (lay->map[i][j] == 'C')
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		all_imgs->collect->img, j * CS, i * CS);
}

//DO NOT FORGET TO FREE < STATUS NOT FREED >
t_all_img	*ft_make_all_images(t_layout *layout)
{
	t_all_img	*all_imgs;

	all_imgs = malloc(sizeof(t_all_img));
	if (!all_imgs)
		return (0);
	all_imgs->background = ft_make_img_xpm("images/background.xpm", layout);
	all_imgs->collect = ft_make_img_xpm("images/collect.xpm", layout);
	all_imgs->wall = ft_make_img_xpm("images/wall.xpm", layout);
	all_imgs->exit = ft_make_img_xpm("images/exit.xpm", layout);
	all_imgs->p_up_0 = ft_make_img_xpm("images/p_up_0.xpm", layout);
	all_imgs->p_up_1 = ft_make_img_xpm("images/p_up_1.xpm", layout);
	all_imgs->p_down_0 = ft_make_img_xpm("images/p_down_0.xpm", layout);
	all_imgs->p_down_1 = ft_make_img_xpm("images/p_down_1.xpm", layout);
	all_imgs->p_right = ft_make_img_xpm("images/p_right_0.xpm", layout);
	all_imgs->p_right_1 = ft_make_img_xpm("images/p_right_1.xpm", layout);
	all_imgs->p_right_2 = ft_make_img_xpm("images/p_right_2.xpm", layout);
	all_imgs->p_left = ft_make_img_xpm("images/p_left_0.xpm", layout);
	all_imgs->p_left_1 = ft_make_img_xpm("images/p_left_1.xpm", layout);
	all_imgs->p_left_2 = ft_make_img_xpm("images/p_left_2.xpm", layout);
	all_imgs->atck_l_0 = ft_make_img_xpm("images/atck_l_0.xpm", layout);
	all_imgs->atck_l_1 = ft_make_img_xpm("images/atck_l_1.xpm", layout);
	all_imgs->atck_l_2 = ft_make_img_xpm("images/atck_l_2.xpm", layout);
	all_imgs->atck_l_3 = ft_make_img_xpm("images/atck_l_3.xpm", layout);
	ft_make_all_images_1(layout, all_imgs);
	return (all_imgs);
}

void	ft_make_all_images_1(t_layout *layout, t_all_img *all_imgs)
{
	all_imgs->atck_l_4 = ft_make_img_xpm("images/atck_l_4.xpm", layout);
	all_imgs->atck_r_0 = ft_make_img_xpm("images/atck_r_0.xpm", layout);
	all_imgs->atck_r_1 = ft_make_img_xpm("images/atck_r_1.xpm", layout);
	all_imgs->atck_r_2 = ft_make_img_xpm("images/atck_r_2.xpm", layout);
	all_imgs->atck_r_3 = ft_make_img_xpm("images/atck_r_3.xpm", layout);
	all_imgs->atck_r_4 = ft_make_img_xpm("images/atck_r_4.xpm", layout);
	all_imgs->e_left = ft_make_img_xpm("images/zom_left_0.xpm", layout);
	all_imgs->e_left_1 = ft_make_img_xpm("images/zom_left_1.xpm", layout);
	all_imgs->e_left_2 = ft_make_img_xpm("images/zom_left_2.xpm", layout);
	all_imgs->e_left_3 = ft_make_img_xpm("images/zom_left_3.xpm", layout);
	all_imgs->e_right_0 = ft_make_img_xpm("images/zom_right_0.xpm", layout);
	all_imgs->e_right_1 = ft_make_img_xpm("images/zom_right_1.xpm", layout);
	all_imgs->e_right_2 = ft_make_img_xpm("images/zom_right_2.xpm", layout);
	all_imgs->e_right_3 = ft_make_img_xpm("images/zom_right_3.xpm", layout);
	all_imgs->e_up = ft_make_img_xpm("images/zom_up.xpm", layout);
	all_imgs->e_up_1 = ft_make_img_xpm("images/zom_up_1.xpm", layout);
	all_imgs->e_down = ft_make_img_xpm("images/zom_down.xpm", layout);
	all_imgs->e_death_1 = ft_make_img_xpm("images/zom_death_1.xpm", layout);
	all_imgs->e_death_2 = ft_make_img_xpm("images/zom_death_2.xpm", layout);
	all_imgs->e_death_3 = ft_make_img_xpm("images/zom_death_3.xpm", layout);
	ft_make_all_images_2(layout, all_imgs);
}

void	ft_make_all_images_2(t_layout *layout, t_all_img *all_imgs)
{
	all_imgs->death_0 = ft_make_img_xpm("images/death_0.xpm", layout);
	all_imgs->death_1 = ft_make_img_xpm("images/death_1.xpm", layout);
	all_imgs->death_2 = ft_make_img_xpm("images/death_2.xpm", layout);
	all_imgs->death_3 = ft_make_img_xpm("images/death_3.xpm", layout);
	all_imgs->death_4 = ft_make_img_xpm("images/death_4.xpm", layout);
	all_imgs->death_5 = ft_make_img_xpm("images/death_5.xpm", layout);
	all_imgs->death_6 = ft_make_img_xpm("images/death_6.xpm", layout);
	all_imgs->death_7 = ft_make_img_xpm("images/death_7.xpm", layout);
}

void	ft_make_all_img_zom_2(t_layout *layout, t_all_img *all_imgs)
{
	all_imgs->e_left = ft_make_img_xpm("images/zom_2_left_0.xpm", layout);
	all_imgs->e_left_1 = ft_make_img_xpm("images/zom_2_left_1.xpm", layout);
	all_imgs->e_left_2 = ft_make_img_xpm("images/zom_2_left_2.xpm", layout);
	all_imgs->e_left_3 = ft_make_img_xpm("images/zom_2_left_3.xpm", layout);
	all_imgs->e_right_0 = ft_make_img_xpm("images/zom_2_right_0.xpm", layout);
	all_imgs->e_right_1 = ft_make_img_xpm("images/zom_2_right_1.xpm", layout);
	all_imgs->e_right_2 = ft_make_img_xpm("images/zom_2_right_2.xpm", layout);
	all_imgs->e_right_3 = ft_make_img_xpm("images/zom_2_right_3.xpm", layout);
	all_imgs->e_up = ft_make_img_xpm("images/zom_2_up.xpm", layout);
	all_imgs->e_up_1 = ft_make_img_xpm("images/zom_2_up_1.xpm", layout);
	all_imgs->e_down = ft_make_img_xpm("images/zom_2_down.xpm", layout);
	all_imgs->e_death_1 = ft_make_img_xpm("images/zom_2_death_1.xpm", layout);
	all_imgs->e_death_2 = ft_make_img_xpm("images/zom_2_death_2.xpm", layout);
	all_imgs->e_death_3 = ft_make_img_xpm("images/zom_2_death_3.xpm", layout);
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
	return (image);
}

void	ft_put_move_number(t_layout *layout)
{
	char	*moves;

	moves = ft_itoa(layout->move_cnt++);
	mlx_put_image_to_window(layout->mlx, layout->mlx_win, \
	layout->all_imgs->wall->img, 0 * CS, 0 * CS);
	mlx_string_put(layout->mlx, layout->mlx_win, 10, 20, 0xffffffff, moves);
	free(moves);
}

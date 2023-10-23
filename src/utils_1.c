/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:25:18 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 12:26:00 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//runs mlx_do_sync to push the images to the screen immediately
//and then waits for int time milisecs
void	ft_mlx_sync(t_layout *layout, int time)
{
	mlx_do_sync(layout->mlx);
	usleep(time);
}

//runs mlx_do_sync to push the images to the screen immediately
//and then waits for int time milisecs
void	ft_mlx_sync_end(t_layout *layout, int time)
{
	mlx_do_sync(layout->end_mlx);
	usleep(time);
}

//Makes image pointer from xpm files for the main mlx pointer
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

//Prints move number in the top of the screen
void	ft_put_move_number(t_layout *layout)
{
	char	*moves;

	moves = ft_itoa(layout->move_cnt++);
	mlx_put_image_to_window(layout->mlx, layout->mlx_win, \
	layout->all_imgs->wall->img, 0 * CS, 0 * CS);
	mlx_string_put(layout->mlx, layout->mlx_win, 10, 20, 0xffffffff, moves);
	free(moves);
}

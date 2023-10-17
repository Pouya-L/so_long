/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:38:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/17 02:41:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_up(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x - 1][lay->player_y];
	if (lay->map[lay->player_x - 1][lay->player_y] == 'E' && \
	lay->n_collect == 0)
		on_destroy(lay);
	else if (lay->map[lay->player_x - 1][lay->player_y] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		*player = '0';
		*next = 'P';
		player_move_up_anim(lay);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_up_0->img, lay->player_y * CS, lay->player_x * CS);
}



void	player_move_up_anim(t_layout *lay)
{
	int	frame;
	clock_t current_time;
	clock_t start_time;
	int	animation_delay;

	animation_delay = 700;
	start_time = clock();
	frame = 0;
	while (frame < 2)
	{
		current_time = clock();
		double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC * 1000;
		if (elapsed_time >= animation_delay)
		{
		if (frame == 0)
			{
			mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
			lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
			mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
			lay->all_imgs->player_up_0->img, lay->player_y * CS, \
			((double)lay->player_x - 0.5) * CS);
			}
			else
			{
			mlx_put_image_to_window(lay->mlx, lay->mlx_win, lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
			mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
			lay->all_imgs->player_up_1->img, lay->player_y * CS, \
			(lay->player_x - 1) * CS);
			}
			frame++;
			start_time = current_time;
		}
	}
}

void	player_move_down(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x + 1][lay->player_y];
	if (lay->map[lay->player_x + 1][lay->player_y] == 'E' && \
	lay->n_collect == 0)
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
		lay->all_imgs->player_down->img, lay->player_y * CS, \
		(lay->player_x + 1) * CS);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_down->img, lay->player_y * CS, \
		lay->player_x * CS);
}

void	player_move_right(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x][lay->player_y + 1];
	if (lay->map[lay->player_x][lay->player_y + 1] == 'E' && \
	lay->n_collect == 0)
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
		lay->all_imgs->player_right->img, (lay->player_y + 1) * \
		CS, lay->player_x * CS);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_right->img, lay->player_y * CS, \
		lay->player_x * CS);
}

void	player_move_left(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x][lay->player_y - 1];
	if (lay->map[lay->player_x][lay->player_y - 1] == 'E' && \
	lay->n_collect == 0)
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
		lay->all_imgs->player_left->img, (lay->player_y - 1) * \
		CS, lay->player_x * CS);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_left->img, lay->player_y * CS, \
		lay->player_x * CS);
}

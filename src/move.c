/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:38:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:40 by plashkar         ###   ########.fr       */
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
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_up->img, lay->player_y * CS, \
		(lay->player_x - 1) * CS);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->player_up->img, lay->player_y * CS, lay->player_x * CS);
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

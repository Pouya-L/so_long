/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:36:52 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 11:45:07 by plashkar         ###   ########.fr       */
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
		ft_win_msg(lay);
	else if (lay->map[lay->player_x - 1][lay->player_y] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
			ft_player_death(lay);
		*player = '0';
		*next = 'P';
		player_move_up_anim(lay);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->p_up_0->img, lay->player_y * CS, lay->player_x * CS);
}

void	player_move_down(t_layout *lay)
{
	char	*player;
	char	*next;

	player = &lay->map[lay->player_x][lay->player_y];
	next = &lay->map[lay->player_x + 1][lay->player_y];
	if (lay->map[lay->player_x + 1][lay->player_y] == 'E' && \
	lay->n_collect == 0)
		ft_win_msg(lay);
	else if (lay->map[lay->player_x + 1][lay->player_y] == 'C')
		lay->n_collect--;
	if (*next != '1' && *next != 'E')
	{
		if (*next == 'Z')
			ft_player_death(lay);
		*player = '0';
		*next = 'P';
		player_move_down_anim(lay);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->p_down_0->img, lay->player_y * CS, \
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
		ft_win_msg(lay);
	else if (lay->map[lay->player_x][lay->player_y + 1] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
			ft_player_death(lay);
		*player = '0';
		*next = 'P';
		player_move_right_anim(lay);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->p_right->img, lay->player_y * CS, \
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
		ft_win_msg(lay);
	else if (lay->map[lay->player_x][lay->player_y - 1] == 'C')
		lay->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
			ft_player_death(lay);
		*player = '0';
		*next = 'P';
		player_move_left_anim(lay);
		ft_put_move_number(lay);
	}
	else
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->p_left->img, lay->player_y * CS, \
		lay->player_x * CS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:36:52 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/06 17:06:20 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_up(t_layout *l)
{
	char	*player;
	char	*next;

	player = &l->map[l->player_x][l->player_y];
	next = &l->map[l->player_x - 1][l->player_y];
	if (l->map[l->player_x - 1][l->player_y] == 'E' && l->n_collect == 0)
		ft_win_msg(l);
	else if (l->map[l->player_x - 1][l->player_y] == 'C')
		l->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
		{
			ft_hurt(l);
			return ;
		}
		*player = '0';
		*next = 'P';
		player_move_up_anim(l);
		ft_put_move_number(l);
	}
	else
		mlx_put_image_to_window(l->mlx, l->mlx_win, \
		l->all_imgs->p_up_0->img, l->player_y * CS, l->player_x * CS);
}

void	player_move_down(t_layout *l)
{
	char	*player;
	char	*next;

	player = &l->map[l->player_x][l->player_y];
	next = &l->map[l->player_x + 1][l->player_y];
	if (l->map[l->player_x + 1][l->player_y] == 'E' && l->n_collect == 0)
		ft_win_msg(l);
	else if (l->map[l->player_x + 1][l->player_y] == 'C')
		l->n_collect--;
	if (*next != '1' && *next != 'E')
	{
		if (*next == 'Z')
		{
			ft_hurt(l);
			return ;
		}
		*player = '0';
		*next = 'P';
		player_move_down_anim(l);
		ft_put_move_number(l);
	}
	else
		mlx_put_image_to_window(l->mlx, l->mlx_win, \
		l->all_imgs->p_down_0->img, l->player_y * CS, \
		l->player_x * CS);
}

void	player_move_right(t_layout *l)
{
	char	*player;
	char	*next;

	player = &l->map[l->player_x][l->player_y];
	next = &l->map[l->player_x][l->player_y + 1];
	if (l->map[l->player_x][l->player_y + 1] == 'E' && l->n_collect == 0)
		ft_win_msg(l);
	else if (l->map[l->player_x][l->player_y + 1] == 'C')
		l->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
		{
			ft_hurt(l);
			return ;
		}
		*player = '0';
		*next = 'P';
		player_move_right_anim(l);
		ft_put_move_number(l);
	}
	else
		mlx_put_image_to_window(l->mlx, l->mlx_win, \
		l->all_imgs->p_right->img, l->player_y * CS, \
		l->player_x * CS);
}

void	player_move_left(t_layout *l)
{
	char	*player;
	char	*next;

	player = &l->map[l->player_x][l->player_y];
	next = &l->map[l->player_x][l->player_y - 1];
	if (l->map[l->player_x][l->player_y - 1] == 'E' && l->n_collect == 0)
		ft_win_msg(l);
	else if (l->map[l->player_x][l->player_y - 1] == 'C')
		l->n_collect--;
	if (*next != 'E' && *next != '1')
	{
		if (*next == 'Z')
		{
			ft_hurt(l);
			return ;
		}
		*player = '0';
		*next = 'P';
		player_move_left_anim(l);
		ft_put_move_number(l);
	}
	else
		mlx_put_image_to_window(l->mlx, l->mlx_win, \
		l->all_imgs->p_left->img, l->player_y * CS, \
		l->player_x * CS);
}

void	ft_hurt(t_layout *lay)
{
	lay->player_health--;
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_0->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_1->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_2->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->death_3->img, lay->player_y * CS, lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	if (lay->player_health == 2)
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->health_2->img, (lay->n_col - 1) * CS, 0 * CS);
	if (lay->player_health == 1)
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->health_1->img, (lay->n_col - 1) * CS, 0 * CS);
	if (lay->player_health == 0)
		ft_player_death(lay);
}

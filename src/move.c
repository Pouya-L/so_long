/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:38:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/17 18:45:01 by plashkar         ###   ########.fr       */
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



void	player_move_up_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_0->img, lay->player_y * CS, \
	((double)lay->player_x - 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_1->img, lay->player_y * CS, \
	((double)lay->player_x - 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_0->img, lay->player_y * CS, \
	((double)lay->player_x - 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_up_1->img, lay->player_y * CS, \
	((double)lay->player_x - 1) * CS);
}

void	ft_mlx_sync(t_layout *layout, int time)
{
	mlx_do_sync(layout->mlx);
	usleep(time);
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

void	player_move_down_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_1->img, lay->player_y * CS, \
	((double)lay->player_x + 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_0->img, lay->player_y * CS, \
	((double)lay->player_x + 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_1->img, lay->player_y * CS, \
	((double)lay->player_x + 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_down_0->img, lay->player_y * CS, \
	((double)lay->player_x + 1) * CS);
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

void	player_move_right_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right->img, (((double)lay->player_y + 0.25) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right_1->img, (((double)lay->player_y + 0.5) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right_2->img, (((double)lay->player_y + 0.75) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_right->img, (((double)lay->player_y + 1) * CS), \
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

void	player_move_left_anim(t_layout *lay)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left->img, (((double)lay->player_y - 0.25) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left_1->img, (((double)lay->player_y - 0.5) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left_2->img, (((double)lay->player_y - 0.75) * CS), \
	lay->player_x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, lay->player_y * CS, lay->player_x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->p_left->img, (((double)lay->player_y - 1) * CS), \
	lay->player_x * CS);
}

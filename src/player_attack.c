/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:20:31 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/06 14:39:09 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Player attack function
//It checks if there is a zombie in the next position if so sets it's is_dead
// pointer to 1 and then sets that poistion to 0 on the map & updates the img
void	player_attack_right(t_layout *lay)
{
	int	i;

	lay->flag_atk_anim_status = 1;
	player_attack_right_anim(lay);
	if (lay->map[lay->player_x][lay->player_y + 1] == 'Z')
	{
		i = 0;
		while (lay->enemies[i] && !lay->enemies[i]->is_dead)
		{
			if (lay->enemies[i]->x == lay->player_x && lay->enemies[i]->y == \
			lay->player_y + 1)
				lay->enemies[i]->is_dead = 1;
			i++;
		}
		enemy_death_anim_right(lay);
		lay->map[lay->player_x][lay->player_y + 1] = '0';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, ((lay->player_y + 1) * CS), \
		(lay->player_x * CS));
	}
	lay->flag_atk_anim_status = 0;
}

//Player attack function
//It checks if there is a zombie in the next position if so sets it's is_dead
// pointer to 1 and then sets that poistion to 0 on the map & updates the img
void	player_attack_left(t_layout *lay)
{
	int	i;

	lay->flag_atk_anim_status = 1;
	player_attack_left_anim(lay);
	if (lay->map[lay->player_x][lay->player_y - 1] == 'Z')
	{
		i = 0;
		while (lay->enemies[i])
		{
			if (lay->enemies[i]->x == lay->player_x && lay->enemies[i]->y == \
			lay->player_y - 1)
				lay->enemies[i]->is_dead = 1;
			i++;
		}
		enemy_death_anim_left(lay);
		lay->map[lay->player_x][lay->player_y - 1] = '0';
		mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
		lay->all_imgs->background->img, ((lay->player_y - 1) * CS), \
		(lay->player_x * CS));
	}
	lay->flag_atk_anim_status = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 13:20:35 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Takes care of key_press functions
int	ft_key_press(int keysymb, t_layout *layout)
{
	ft_player_and_exit_coordinates(layout);
	if (keysymb == K_ESC)
		on_destroy(layout);
	ft_key_press_player(keysymb, layout);
	if (keysymb == KEY_B)
		ft_make_all_img_zom_2(layout, layout->all_imgs);
	return (0);
}

void	ft_key_press_player(int keysymb, t_layout *layout)
{
	if (keysymb == KEY_W || keysymb == DIRK_UP)
		player_move_up(layout);
	else if (keysymb == KEY_A || keysymb == DIRK_LEFT)
		player_move_left(layout);
	else if (keysymb == KEY_S || keysymb == DIRK_DOWN)
		player_move_down(layout);
	else if (keysymb == KEY_D || keysymb == DIRK_RIGHT)
		player_move_right(layout);
	else if (keysymb == KEY_E)
		player_attack_right(layout);
	else if (keysymb == KEY_Q)
		player_attack_left(layout);
}

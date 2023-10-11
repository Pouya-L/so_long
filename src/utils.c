/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/11 17:53:46 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_layout *layout)
{
	int	i;

	i = 0;
	mlx_destroy_image(layout->mlx, layout->all_imgs->background->img);
	free(layout->all_imgs->background);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_up->img);
	free(layout->all_imgs->player_up);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_down->img);
	free(layout->all_imgs->player_down);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_right->img);
	free(layout->all_imgs->player_right);
	mlx_destroy_image(layout->mlx, layout->all_imgs->player_left->img);
	free(layout->all_imgs->player_left);
	on_destroy_2 (layout);
	free(layout->all_imgs);
	mlx_destroy_window(layout->mlx, layout->mlx_win);
	mlx_destroy_display(layout->mlx);
	while (i <= layout->n_enemy)
		free(layout->enemies[i++]);
	free_2d_array(layout->map);
	free(layout->mlx);
	exit (0);
}

void	on_destroy_2(t_layout *layout)
{	int	i;

	i = 0;
	mlx_destroy_image(layout->mlx, layout->all_imgs->collect->img);
	free(layout->all_imgs->collect);
	mlx_destroy_image(layout->mlx, layout->all_imgs->wall->img);
	free(layout->all_imgs->wall);
	mlx_destroy_image(layout->mlx, layout->all_imgs->exit->img);
	free(layout->all_imgs->exit);
	mlx_destroy_image(layout->mlx, layout->all_imgs->enemy->img);
	free(layout->all_imgs->enemy);
}
int	ft_key_press(int keysymb, t_layout *layout)
{
	ft_player_and_exit_coordinates(layout);
	ft_enemy_move(layout);
		ft_printf("Pressed key: %d\n", keysymb);
	if (keysymb == K_ESC)
		on_destroy(layout);
	if (keysymb == KEY_W || keysymb == DIRK_UP)
		player_move_up(layout);
	if (keysymb == KEY_A || keysymb == DIRK_LEFT)
		player_move_left(layout);
	if (keysymb == KEY_S || keysymb == DIRK_DOWN)
		player_move_down(layout);
	if (keysymb == KEY_D ||keysymb == DIRK_RIGHT)
		player_move_right(layout);
	ft_hit_enemy_check(layout);
			ft_printf("\nThe move count is %d \n", layout->move_cnt);


	return (0);
}



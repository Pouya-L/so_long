/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/17 19:38:51 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_layout *layout)
{
	int	i;

	i = 0;
	mlx_destroy_image(layout->mlx, layout->all_imgs->background->img);
	free(layout->all_imgs->background);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_up_0->img);
	free(layout->all_imgs->p_up_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_up_1->img);
	free(layout->all_imgs->p_up_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_down_0->img);
	free(layout->all_imgs->p_down_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_down_1->img);
	free(layout->all_imgs->p_down_1);
	on_destroy_1(layout);
	on_destroy_2(layout);
	free(layout->all_imgs);
	mlx_destroy_window(layout->mlx, layout->mlx_win);
	mlx_destroy_display(layout->mlx);
	while (i < layout->n_enemy)
		free(layout->enemies[i++]);
	free_2d_array(layout->map);
	free(layout->mlx);
	exit (0);
}

void	on_destroy_1(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->collect->img);
	free(layout->all_imgs->collect);
	mlx_destroy_image(layout->mlx, layout->all_imgs->wall->img);
	free(layout->all_imgs->wall);
	mlx_destroy_image(layout->mlx, layout->all_imgs->exit->img);
	free(layout->all_imgs->exit);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_left->img);
	free(layout->all_imgs->e_left);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_right->img);
	free(layout->all_imgs->p_right);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_right_1->img);
	free(layout->all_imgs->p_right_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_right_2->img);
	free(layout->all_imgs->p_right_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_left->img);
	free(layout->all_imgs->p_left);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_left_1->img);
	free(layout->all_imgs->p_left_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_left_2->img);
	free(layout->all_imgs->p_left_2);
}

void	on_destroy_2(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_left_1->img);
	free(layout->all_imgs->e_left_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_left_2->img);
	free(layout->all_imgs->e_left_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_left_3->img);
	free(layout->all_imgs->e_left_3);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_right_0->img);
	free(layout->all_imgs->e_right_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_right_1->img);
	free(layout->all_imgs->e_right_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_right_2->img);
	free(layout->all_imgs->e_right_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_right_3->img);
	free(layout->all_imgs->e_right_3);
}
int	ft_key_press(int keysymb, t_layout *layout)
{

	ft_player_and_exit_coordinates(layout);
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
	return (0);
}



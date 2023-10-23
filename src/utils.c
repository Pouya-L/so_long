/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/23 02:53:20 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_layout *layout)
{
	int	i;

	i = 0;
	mlx_destroy_image(layout->mlx, layout->all_imgs->background->img);
	free(layout->all_imgs->background);
	mlx_destroy_image(layout->mlx, layout->all_imgs->collect->img);
	free(layout->all_imgs->collect);
	mlx_destroy_image(layout->mlx, layout->all_imgs->wall->img);
	free(layout->all_imgs->wall);
	mlx_destroy_image(layout->mlx, layout->all_imgs->exit->img);
	free(layout->all_imgs->exit);
	on_destroy_1(layout);
	on_destroy_2(layout);
	on_destroy_3(layout);
	free(layout->all_imgs);
	mlx_destroy_window(layout->mlx, layout->mlx_win);
	mlx_destroy_display(layout->mlx);
	while (i < layout->n_enemy)
		free(layout->enemies[i++]);
	free_2d_array(layout->map);
	free(layout->mlx);
	if (layout->flag_game_over == 1)
		return (0);
	else
		exit (0);
}

void	on_destroy_1(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_up_0->img);
	free(layout->all_imgs->p_up_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_up_1->img);
	free(layout->all_imgs->p_up_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_down_0->img);
	free(layout->all_imgs->p_down_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->p_down_1->img);
	free(layout->all_imgs->p_down_1);
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
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_up->img);
	free(layout->all_imgs->e_up);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_up_1->img);
	free(layout->all_imgs->e_up_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_down->img);
	free(layout->all_imgs->e_down);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_left->img);
	free(layout->all_imgs->e_left);
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
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_death_1->img);
	free(layout->all_imgs->e_death_1);
}

void	on_destroy_3(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_0->img);
	free(layout->all_imgs->death_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_1->img);
	free(layout->all_imgs->death_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_2->img);
	free(layout->all_imgs->death_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_3->img);
	free(layout->all_imgs->death_3);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_4->img);
	free(layout->all_imgs->death_4);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_5->img);
	free(layout->all_imgs->death_5);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_6->img);
	free(layout->all_imgs->death_6);
	mlx_destroy_image(layout->mlx, layout->all_imgs->death_7->img);
	free(layout->all_imgs->death_7);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_death_2->img);
	free(layout->all_imgs->e_death_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->e_death_3->img);
	free(layout->all_imgs->e_death_3);
	on_destroy_4(layout);
}

void	on_destroy_4(t_layout *layout)
{
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_l_0->img);
	free(layout->all_imgs->atck_l_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_l_1->img);
	free(layout->all_imgs->atck_l_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_l_2->img);
	free(layout->all_imgs->atck_l_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_l_3->img);
	free(layout->all_imgs->atck_l_3);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_l_4->img);
	free(layout->all_imgs->atck_l_4);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_r_0->img);
	free(layout->all_imgs->atck_r_0);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_r_1->img);
	free(layout->all_imgs->atck_r_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_r_2->img);
	free(layout->all_imgs->atck_r_2);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_r_3->img);
	free(layout->all_imgs->atck_r_3);
	mlx_destroy_image(layout->mlx, layout->all_imgs->atck_r_4->img);
	free(layout->all_imgs->atck_r_4);
}

int	ft_key_press(int keysymb, t_layout *layout)
{
	ft_player_and_exit_coordinates(layout);
	if (keysymb == K_ESC)
		on_destroy(layout);
	else if (keysymb == KEY_W || keysymb == DIRK_UP)
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
	else if (keysymb == KEY_B)
		ft_make_all_img_zom_2(layout, layout->all_imgs);
	return (0);
}

void	ft_mlx_sync(t_layout *layout, int time)
{
	mlx_do_sync(layout->mlx);
	usleep(time);
}

void	ft_mlx_sync_end(t_layout *layout, int time)
{
	mlx_do_sync(layout->end_mlx);
	usleep(time);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:05:50 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/06 16:23:01 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Free functions for imgs created by mlx and the pointers assigned by me.
It runs on destroy_1 & destroy_2 & destroy_3 before destroying the window
& display. then it frees the 2d array where the map is stored finally it frees
 the mlx pointer and depending on the flag of game_over it exits or returns */
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

//helper to on_destroy, needed due to line count limitation
//destroys player images
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
	mlx_destroy_image(layout->mlx, layout->all_imgs->health_1->img);
	free(layout->all_imgs->health_1);
	mlx_destroy_image(layout->mlx, layout->all_imgs->health_2->img);
	free(layout->all_imgs->health_2);
}

//helper to on_destroy, needed due to line count limitation
//destroys enemy images
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

//helper to on_destroy, needed due to line count limitation
//destroys player death animation frames
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
	mlx_destroy_image(layout->mlx, layout->all_imgs->health_3->img);
	free(layout->all_imgs->health_3);
	on_destroy_4(layout);
}

//helper to on_destroy, needed due to line count limitation
//destroys player attack animation frames
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

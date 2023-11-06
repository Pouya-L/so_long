/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:47:43 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/06 17:30:43 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Initializes the mlx pointer, creates the window realted to the size of map,
//Puts the initial images to the window. Inits the enemies at random x and y
//Makes each of those enemies move randomly and loops it through mlx_loop_hook
//loops ft_key_press and on_destory on click x to listen for user inputs always
int	game_init(t_layout *layout)
{
	layout->mlx = mlx_init();
	layout->mlx_win = mlx_new_window(layout->mlx, layout->n_col * CS, \
	layout->n_row * CS, "My game");
	if (!layout->mlx_win)
		return (free(layout->mlx), 1);
	ft_initial_map_to_screen(layout);
	ft_make_enemies(layout);
	mlx_loop_hook(layout->mlx, ft_enemy_move_gen, layout);
	mlx_hook(layout->mlx_win, 2, 1L << 0, ft_key_press, layout);
	mlx_hook(layout->mlx_win, 17, 0, on_destroy, layout);
	mlx_loop(layout->mlx);
	return (0);
}

//Puts the initial images to the window. Essentialy rendering the 1st frame
////Set the player health to 3 & puts the 3 hearts in the top right corner
void	ft_initial_map_to_screen(t_layout *layout)
{
	int	i;
	int	j;

	i = 0;
	layout->all_imgs = ft_make_all_images(layout);
	layout->player_health = 3;
	while (layout->map[i])
	{
		j = 0;
		while (layout->map[i][j])
		{
			ft_map_characters(layout, layout->all_imgs, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(layout->mlx, layout->mlx_win, \
	layout->all_imgs->health_3->img, (layout->n_col - 1) * CS, 0 * CS);
}

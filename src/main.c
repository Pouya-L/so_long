/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:56:33 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/09 17:52:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_layout	layout;

	ft_check_params(argc, argv);
	ft_memset(&layout, 0, sizeof(layout));
	ft_map_allocate(&layout, argv);
	ft_player_and_exit_coordinates(&layout);
		print_map_details(&layout);
	ft_map_validations(&layout);
	game_init(&layout);
	return (0);
}



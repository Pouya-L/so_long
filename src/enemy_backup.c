/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_backup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:54 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/17 16:49:07 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_enemy	*ft_spawn_enemies(t_layout *lay)
{
	size_t	i;
	size_t	j;

	ft_randomize_i_and_j(lay, &i, &j);
	while (lay->map[i] && i < lay->n_row - 1 && j < lay->n_col - 1)
	{
		while (lay->map[i][j])
		{
			if (lay->map[i][j] == '0')
				return (ft_spawn_enemies_check(lay, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

t_enemy	*ft_spawn_enemies_check(t_layout *lay, size_t i, size_t j)
{
	int		e;

	e = lay->n_enemy + 1;
	while (e--)
	{
		if (lay->enemies[e - 1]->x != i && lay->enemies[e - 1]->y != j)
		{

		}

	}
	return (0);
}

t_enemy	*init_enemy(size_t i, size_t j)
{
	t_enemy	*enemy;

	enemy = ft_calloc (1, sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->x = i;
	enemy->y = j;
	return (enemy);
}

void	ft_make_enemies(t_layout *layout)
{
	int	i;
	int	j;
	t_enemy	*new_enemy;

	i = rand() % 10;
	j = 0;
	while (i > 0 && j < MAX_ENEMIES)
	{
		new_enemy = ft_spawn_enemies(layout);
		if (new_enemy)
		{
			layout->enemies[j] = new_enemy;
			j++;
		}
		i--;
	}
	layout->n_enemy = j;
}

void	ft_hit_enemy_check(t_layout *layout)
{
	int	i;

	i = 0;
	while(i < layout->n_enemy)
	{
		if (layout->player_x == layout->enemies[i]->x && layout->player_y \
		== layout->enemies[i]->y)
		{
			on_destroy(layout);
			exit(0);
		}
		i++;
	}
}

int	ft_enemy_move_gen(t_layout *layout)
{
	int	move_x;
	int	move_y;
	size_t new_x;
	size_t new_y;
	int	i;

	i = 0;
	ft_hit_enemy_check(layout);
	while (layout->enemies[i])
	{
		move_x = (rand() % 3 - 1);
		move_y = (rand() % 3 - 1);
		if (move_x != 0 && move_y != 0)
			move_x = 0;
		new_x = layout->enemies[i]->x + move_x;
		new_y = layout->enemies[i]->y + move_y;
		if (layout->map[new_x][new_y] == '0')
		ft_enemy_move(layout, layout->enemies[i], new_x, new_y);
		i++;
	}
	return (0);
}
void	ft_enemy_move(t_layout *lay, t_enemy *enemy, size_t new_x, size_t new_y)
{
	int	i;

	i = 0;
	while (lay->enemies[i])
	{
		if (lay->enemies[i]->x != new_x && lay->enemies[i]->y != new_y)
		{
			if (new_x == enemy->x - 1)
				enemy_move_up_anim(lay, enemy);
			if (new_x == enemy->x + 1)
				enemy_move_down_anim(lay, enemy);
			if (new_y == enemy->y - 1)
				enemy_move_left_anim(lay, enemy);
			if (new_y == enemy->y + 1)
				enemy_move_right_anim(lay, enemy);
			enemy->y = new_y;
			enemy->x = new_x;
		}
		i++;
	}
}
void	enemy_move_up_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x - 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up->img, enemy->y * CS, \
	((double)enemy->x - 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x - 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_up->img, enemy->y * CS, \
	((double)enemy->x - 1) * CS);
}

void	enemy_move_down_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x + 0.25) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_down->img, enemy->y * CS, \
	((double)enemy->x + 0.5) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, enemy->y * CS, \
	((double)enemy->x + 0.75) * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_down->img, enemy->y * CS, \
	((double)enemy->x + 1) * CS);
}

void	enemy_move_right_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_0->img, (((double)enemy->y + 0.25) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_1->img, (((double)enemy->y + 0.5) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_2->img, (((double)enemy->y + 0.75) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_right_3->img, (((double)enemy->y + 1) * CS), \
	enemy->x * CS);
}

void	enemy_move_left_anim(t_layout *lay, t_enemy *enemy)
{
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left->img, (((double)enemy->y - 0.25) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_1->img, (((double)enemy->y - 0.5) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_2->img, (((double)enemy->y - 0.75) * CS), \
	enemy->x * CS);
	ft_mlx_sync(lay, 100000);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->background->img, enemy->y * CS, enemy->x * CS);
	mlx_put_image_to_window(lay->mlx, lay->mlx_win, \
	lay->all_imgs->e_left_3->img, (((double)enemy->y - 1) * CS), \
	enemy->x * CS);
}

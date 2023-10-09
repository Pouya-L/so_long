/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:12:02 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/09 12:32:04 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_layout	layout;
	char		*map_str;
	char 		**map;
	int			fd;

	fd = ft_check_params(argc, argv);
	map_str = check_map(fd, &layout);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
	 error_msg_and_free("Memory allocation failed", NULL);
	// init_game(map, layout);
	return (0);
}

int	ft_print_map_errors(t_map_error *map_err,char *map_str)
{
	if (map_err->inv_border)
		error_msg_and_free("The map must be surrounded by walls", map_str);
	if (map_err->inv_char)
		error_msg_and_free("Invalid char present", map_str);
	if (map_err->inv_collect)
		error_msg_and_free("Invalid number of collectibles", map_str);
	if (map_err->inv_exit)
		error_msg_and_free("Invalid number of exits", map_str);
	if (map_err->inv_player)
		error_msg_and_free("Invalid number of players", map_str);
	if (map_err->inv_shape)
		error_msg_and_free("The map must be a rectangular shape", map_str);
	return (0);
}

char	*check_map(int fd, t_layout	*layout)
{
	char		*map_str;
	t_map_error	map_err;

	map_str = NULL;
	map_err = ft_memset_map_error();
	*layout = ft_memset_layout();
	ft_read_layout(fd, layout, &map_err, map_str);
	ft_print_map_errors(&map_err, map_str);
	return (map_str);
}


//The first free(last_line) (is used to release the memory allocated
//for the previous last_line. It occurs just before last_line is assigned
//a new value with last_line = ft_substr(line, 0, ft_strlen(line));.
//This is done to prevent memory leaks. Before last_line gets a new value,
//the old value needs to be freed to avoid memory leaks.
//The second free(last_line) occurs when the loop exits (when line becomes NULL),
// and it's used to free the memory allocated for the last line processed.
//This ensures that any memory allocated for last_line during the last
//iteration of the loop is properly deallocated before the function exits.

void	ft_read_layout(int fd, t_layout *layout, t_map_error *map_err, char *map_str)
{
	char	*last_line;
	char	*line;

	last_line = NULL;
	line = NULL;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!layout->col)
				error_msg_and_free("Map is empty", NULL);
			else
				ft_check_layout(last_line, layout, map_err, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_check_layout(line, layout, map_err, !layout->row);
		last_line = ft_substr(line, 0 , ft_strlen(line));
		map_str = ft_strjoin(map_str, line);
		layout->row++;
	}
}


//how would it check the upper border???
void	ft_check_layout(char *line, t_layout *layout, t_map_error *map_err, int is_last)
{
	int	i;

	i = 0;
	if (!layout->col)
		layout->col = ft_strlen(line) - 1;
	if ((layout->col && layout->col != ft_strlen(line) - 1 && ft_strchr(line, '\n')) \
	|| (layout->col && layout->col != ft_strlen(line) && !ft_strchr(line, '\n')))
		map_err->inv_shape = 1;
	if (line[1] != 1 || line[ft_strlen(line) - 1] != '1' || \
	((size_t)ft_countchar(line, '1') != layout->col && is_last))
		map_err->inv_border = 1;
	layout->player += ft_countchar(line, 'P');
	layout->exit += ft_countchar(line, 'E');
	layout->collect += ft_countchar(line, 'C');
	layout->enemy += ft_countchar(line, 'G');
	map_err->inv_collect = layout->collect < 1;
	map_err->inv_exit = layout->exit < 1;
	map_err->inv_player = layout->player < 1;
	while (line[i])
	{
		if (!ft_strchr("01CEP\n", line[i]))
			map_err->inv_char = 1;
		i++;
	}
}

int	ft_check_params(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		error_msg_and_free("Number of arguments not supported", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_and_free("file not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	return (fd);
}

int	error_msg_and_free(char *msg, char *map_str)
{
	if (map_str)
		free(map_str);
	ft_printf("%sError\n%s%s", RED, msg, DEFAULT);
	exit (0);
}

t_map_error ft_memset_map_error(void)
{
	t_map_error	map_err;
	map_err.inv_exit = 0;
	map_err.inv_player = 0;
	map_err.inv_collect = 0;
	map_err.inv_shape = 0;
	map_err.inv_border = 0;
	map_err.inv_char = 0;
	return (map_err);
}

t_layout ft_memset_layout(void)
{
	t_layout	layout;
	layout.row = 0;
	layout.col = 0;
	layout.exit = 0;
	layout.player = 0;
	layout.enemy = 0;
	layout.collect = 0;
	return (layout);
}

// int main()
// {
// 	char *str1 = NULL;
// 	char *str2 = "Hell";
// 	ft_printf("%s", ft_strjoin(str1, str2));
// }


#include <stdio.h>
#include <stdbool.h>

typedef struct s_layout {
    size_t n_row;
    size_t n_col;
    int n_exit;
    int exit_x;
    int exit_y;
    int n_player;
    int player_x;
    int player_y;
    int n_enemy;
    int n_collect;
    int inv_char;
    char **map;
} t_layout;

bool visited[ROWS][COLS] = {false};

// Function to check if a cell is valid
bool isValid(int row, int col, t_layout *layout) {
    return (row >= 0 && row < layout->n_row && col >= 0 && col < layout->n_col);
}

// Function to check if there is a path from 'start' to 'end'
bool doesPathExist(int startRow, int startCol, int exitRow, int exitCol, t_layout *layout) {
    // If we reach the exit, return true
    if (startRow == exitRow && startCol == exitCol) {
        return true;
    }

    visited[startRow][startCol] = true;

    // Define possible moves (up, down, left, right)
    int rowMoves[] = {-1, 1, 0, 0};
    int colMoves[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = startRow + rowMoves[i];
        int newCol = startCol + colMoves[i];

        if (isValid(newRow, newCol, layout) && !visited[newRow][newCol] && layout->map[newRow][newCol] != '1') {
            if (doesPathExist(newRow, newCol, exitRow, exitCol, layout)) {
                return true;
            }
        }
    }

    return false;
}

// Function to check if all collectibles can be collected
bool canCollectAllCollectibles(t_layout *layout) {
    int collectiblesLeft = layout->n_collect;

    // Find the starting position
    int startRow = layout->player_x;aaslayout->player_y;

    // Iterate through the maze and check if there's a path from player to each collectible
    for (int i = 0; i < layout->n_row; i++) {
        for (int j = 0; j < layout->n_col; j++) {
            if (layout->map[i][j] == 'C') {
                visited[ROWS][COLS] = {false}; // Reset visited array for each collectible check
                if (doesPathExist(startRow, startCol, i, j, layout)) {
                    collectiblesLeft--;
                }
            }
        }
    }

    return collectiblesLeft == 0;
}

int main() {
    t_layout layout;

    // Populate layout with your map and other information

    // Check if there is a path from start to exit
    if (doesPathExist(layout.player_x, layout.player_y, layout.exit_x, layout.exit_y, &layout)) {
        printf("Path to the exit exists!\n");
    } else {
        printf("No valid path to the exit.\n");
    }

    // Check if all collectibles can be collected
    if (canCollectAllCollectibles(&layout)) {
        printf("All collectibles can be collected!\n");
    } else {
        printf("Not all collectibles can be collected.\n");
    }

    return 0;
}

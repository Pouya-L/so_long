#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_layout	layout;

	ft_check_params(argc, argv);
	ft_memset(&layout, 0, sizeof(layout));
	ft_map_allocate(&layout, argv);
		ft_printf("Number of collumns %d\n", layout.n_col);
		ft_printf("Number of rows %d\n", layout.n_row);
	ft_map_validations(&layout);
	return (0);
}

void	ft_map_validations(t_layout *layout)
{
	if (!ft_first_and_last(layout) || !ft_borders(layout))
		error_msg_and_free("Invalid borders", NULL);
}

int	ft_first_and_last(t_layout *layout)
{
	int check;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (layout->map[0][i] == '1')
		i++;
	while (layout->map[layout->n_row - 1][j] == '1')
		j++;
	if ((i == (size_t)ft_strlen(layout->map[0]) - 1) && \
	(j == (size_t)ft_strlen(layout->map[layout->n_row - 1]) - 1))
		check = 1;
	else
		check = 0;
	return (check);
}

int	ft_borders(t_layout *layout)
{
	int		check;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	// ft_printf(&layout->map[0][4]);
	while (i < layout->n_row - 1 && layout->map[i][0] == '1')
		i++;
	while (j < layout->n_row - 1 && layout->map[j][layout->n_row - 1] == '1')
		j++;

			// ft_printf("\ni is %d\n", i);
			// ft_printf("\nj is %d\n", j);
			// ft_printf("\ni is supposed to be%d\n", layout->n_row - 1);
			// ft_printf("\nj is supposed to be%d\n", layout->n_row - 1);

	if (i == layout->n_row - 1 && j == layout->n_row - 1)
		check = 1;
	else
		check = 0;
	return (check);
}


void	ft_map_allocate(t_layout *layout, char **argv)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	layout->n_row = ft_count_lines(argv);
	if (layout->n_row <= 2)
		error_msg_and_free("Invalid map shape", NULL);

	layout->map = calloc(layout->n_row, sizeof(char *));
	if (layout->map == NULL)
		error_msg_and_free("Memory allocation failed", NULL);

	while (i < layout->n_row)
	{
		layout->map[i] = NULL;
		i++;
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < layout->n_row)
	{
		layout->map[i] = get_next_line(fd);
		i++;
	}
	layout->n_col = ft_strlen(layout->map[0]) - 1;
	i = 0;
	while (i < layout->n_row)
	{
		if (ft_strlen(layout->map[i]) != layout->n_col + 1)
			error_msg_and_free("The map must be rectangular", layout->map);
		i++;
	}
	close(fd);
}

int	ft_count_lines(char **argv)
{
	int		line_cnt;
	char	*line;
	int		fd;

	line_cnt = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		line_cnt++;
	}
	free(line);
	close(fd);
	return (line_cnt);
}

void	ft_check_params(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		error_msg_and_free("Number of arguments not supported", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_and_free("file not found", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_and_free("Invalid file type, use .ber files as map", NULL);
	close(fd);
}

int	error_msg_and_free(char *msg, char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	ft_printf("%sError\n%s%s\n", RED, msg, DEFAULT);
	exit (0);
}

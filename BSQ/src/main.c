#include "../include/bsq.h"

int read_and_fill(int fd, char *buffer, int **matrix, t_settings *settings)
{
	int read_bytes;
	int index_x;
	int index_y;
	int index;

	index_y = -1;
	while ((read_bytes = read(fd, buffer, BYTE_COUNT)) != 0)
	{
		index = 0;
		while (index < read_bytes)
		{
			if (buffer[index] == '\n')
				down_vertical(&index_x, &index_y);
			else if (index_y >= 0)
			{
				if (index_x > settings->width - 1 || index_y > settings->height - 1)
					return (1);
				process_map_item(buffer[index] == settings->obstacle ? 1 : 0, &index_x, &index_y, matrix);
			}
			index++;
		}
	}
	return (0);
}

int fill_matrix(int **matrix, t_settings *settings, char *file)
{
	int fd;
	char *buffer;
	int code;

	if ((fd = ft_try_open_file(file)) < 0)
		return (1);
	buffer = (char *) malloc(sizeof(char) * (BYTE_COUNT + 1));
	ft_fill_str(buffer, BYTE_COUNT);
	code = read_and_fill(fd, buffer, matrix, settings);
	free(buffer);
	close(fd);
	return (code);
}

void ft_full_map(int **matrix, t_settings *settings)
{
	int i;
	int j;

	i = 0;
	while (i < settings->max_size)
	{
		j = 0;
		while (j < settings->max_size)
		{
			matrix[settings->y + i][settings->x + j] = -1;
			j++;
		}
		i++;
	}
}

int ft_print_map(char *file)
{
	t_settings *settings;
	int **matrix;

	if (!(settings = create_settings()))
		return (1);
	if (ft_get_settings(&settings, file) < 0)
		return (1);
	if (!(matrix = malloc_matrix(settings)))
		return (1);
	fill_empty_matrix(matrix, settings);
	if (fill_matrix(matrix, settings, file) != 0)
		return (1);
	else
	{
		ft_scan_map(matrix, settings); // ft_print_filled_map(matrix, settings);
		ft_full_map(matrix, settings);
		ft_print_filled_map(matrix, settings);
		free(settings);
		return (0);
	}
}

int main(int argc, char *argv[])
{
	argc = 3;
	argv[1] = "/Users/hedgi/CLionProjects/21school/BSQ/map.txt";
	argv[2] = "/Users/hedgi/CLionProjects/21school/BSQ/map2.txt";

	int index;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			if (ft_print_map(argv[index]) != 0)
				ft_putstr("map error\n");
			index++;
		}
	}
	return 0;
}

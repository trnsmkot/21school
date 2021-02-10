#include "../include/bsq.h"

int check_item(char ch, t_settings *settings)
{
	if (ch != settings->empty && ch != settings->obstacle)
		return (0);
	return (1);
}

int read_and_fill(int fd, char *buffer, int **matrix, t_settings *settings)
{
	int read_bytes;
	unsigned long index_x;
	unsigned long index_y;
	int index;

	index_y = 1;
	index_x = 0;
	while ((read_bytes = read(fd, buffer, BYTE_COUNT)) != 0)
	{
		index = 0;
		while (index < read_bytes)
		{
			if (buffer[index] == '\n')
				if (index_x != (settings->width))
					return (0);
				else
					down_vertical(&index_x, &index_y);
			else if (index_x > settings->width - 1 || index_y > settings->height - 1 || !check_item(buffer[index], settings))
				return (0);
			else
				process_map_item(buffer[index] == settings->obstacle ? 1 : 0, &index_x, &index_y, matrix);
			index++;
		}
	}
	return (1);
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

int fill_first_line_matrix(int **matrix, t_settings *settings, const char *line)
{
	unsigned long index_x = 0;
	unsigned long index_y = 0;

	while (index_x < settings->width)
	{
		if (!check_item(line[index_x], settings))
			return (0);
		process_map_item(line[index_x] == settings->obstacle ? 1 : 0, &index_x, &index_y, matrix);
	}
	return (1);
}

int fill_matrix(int **matrix, t_settings *settings, int fd)
{
	char *buffer;
	int code;

	buffer = (char *) malloc(sizeof(char) * (BYTE_COUNT + 1));
	if (!buffer)
		return (0);
	ft_fill_str(buffer, BYTE_COUNT);
	code = read_and_fill(fd, buffer, matrix, settings);
	free(buffer);
	close(fd);
	return (code);
}
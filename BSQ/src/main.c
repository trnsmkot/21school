#include <fcntl.h>
#include <stdlib.h>
#include <printf.h>
#include "../include/bsq.h"

// open, close, read, write, malloc, free, exit
int ft_try_open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("map error\n");
		return (-1);
	}
	return (fd);
}

int ft_get_num(const char *buffer, int size)
{
	int index;
	int sum;

	sum = 0;
	index = 0;
	while (index < size)
	{
		if (buffer[index] < '0' || buffer[index] > '9')
			return (0);
		sum = (sum * 10) + (buffer[index] - '0');
		index++;
	}
	return (sum);
}

int ft_parse_settings(t_settings **settings, char *buffer)
{
	int size;
	t_settings *sett;

	sett = *settings;
	if (sett->height == 0)
	{
		if ((size = ft_index_of(buffer, '\n', 0)) < 0)
			return (0);

		sett->empty = buffer[size - 3];
		sett->obstacle = buffer[size - 2];
		sett->full = buffer[size - 1];
		sett->height = ft_get_num(buffer, size - 3);
		if (sett->height < 1)
			return (0);
	}
	return (1);
}

int count_width(t_settings **sett, const char *buffer, int read_bytes, int n_count)
{
	int n_index;
	int n_index2;
	t_settings *settings;

	settings = *sett;
	if ((n_index = ft_index_of(buffer, '\n', 0)) >= 0)
	{
		if (n_count == 0)
		{
			if ((n_index2 = ft_index_of(buffer, '\n', n_index + 1)) > 0)
			{
				n_count++;
				settings->width += n_index2 - (n_index + 1);
			}
			else
				settings->width += read_bytes - (n_index + 1);
		}
		else
			settings->width += n_index;
		n_count++;
	}
	else
		settings->width += read_bytes;
	return (n_count);
}

void ft_get_settings(t_settings **sett, char *file)
{
	t_settings *settings;
	char *buffer;
	int fd;
	int read_bytes;
	int n_count;

	settings = *sett;
	if ((fd = ft_try_open_file(file)) < 0)
		return;

	buffer = (char *) malloc(sizeof(char) * BYTE_COUNT);
	ft_fill_str(buffer, BYTE_COUNT);
	n_count = 0;
	while ((read_bytes = read(fd, buffer, BYTE_COUNT)) != 0)
	{
		ft_parse_settings(&settings, buffer);
		n_count = count_width(&settings, buffer, read_bytes, n_count);
		if (n_count > 1)
			break;
	}

	free(buffer); // TODO
	close(fd);
}

char **malloc_matrix(t_settings *settings)
{
	int index;
	char **matrix;

	matrix = (char **) malloc(sizeof(char *) * settings->height);
	index = 0;
	while (index < settings->height)
	{
		matrix[index] = (char *) malloc(sizeof(char) * settings->width);
		ft_fill_str(matrix[index], settings->width);
		index++;
	}
	return matrix;
}

// [x][y]
void fill_empty_matrix(char **matrix, t_settings *settings)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < settings->height)
	{
		j = 0;
		while (j < settings->width)
		{
			matrix[i][j] = settings->empty;
			j++;
		}
		i++;
	}
}

int fill_matrix(char **matrix, t_settings *settings, char *file)
{
	int fd;
	char *buffer;
	int read_bytes;
	int n_count;
	int index;
	int m_index;

	m_index = 0;
	n_count = -1;

	if ((fd = ft_try_open_file(file)) < 0)
		return (1);

	buffer = (char *) malloc(sizeof(char) * (BYTE_COUNT + 1));
	ft_fill_str(buffer, BYTE_COUNT);
	while ((read_bytes = read(fd, buffer, BYTE_COUNT)) != 0)
	{
		index = 0;
		while (index < read_bytes)
		{
			if (buffer[index] == '\n')
			{
				n_count++;
				m_index = 0;
			}
			else if (n_count >= 0)
			{
				if (m_index > settings->width - 1 || n_count > settings->height - 1)
				{
					return (1);
				}
				matrix[n_count][m_index] = buffer[index];
				m_index++;
			}

			index++;
		}
	}
	free(buffer);
	return close(fd);
}

void ft_print_filled_map(char **matrix, t_settings *settings)
{
	int i;
	int j;

	printf("%d %d [%c] [%c] [%c]\n", settings->height, settings->width, settings->empty, settings->obstacle, settings->full);

	i = 0;
	while (i < settings->height)
	{
		j = 0;
		printf("%d: ", i);
		while (j < settings->width)
		{
			printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void ft_echo_in_map(char **matrix, t_settings *settings, int i, int j)
{
	int offset;
	int height;
	int width;
	int index_i;
	int index_j;

	height = settings->height - i - 1;
	width = settings->width - j - 1;
	offset = 1;
	while (offset < height && offset < width)
	{
		index_i = 0;
		while (index_i <= offset)
		{
			index_j = 0;
			while (index_j <= offset)
			{
				if (matrix[i + index_i][j + index_j] != settings->empty)
					return;
				index_j++;
			}
			index_i++;
		}
		settings->max_size = offset + 1;
		offset++;
	}

}

void ft_scan_map(char **matrix, t_settings *settings)
{
	int i;
	int j;
	t_settings *tmp_settings;

	tmp_settings = (t_settings *) malloc(sizeof(t_settings));

	tmp_settings->empty = settings->empty;
	tmp_settings->obstacle = settings->obstacle;
	tmp_settings->height = settings->height;
	tmp_settings->width = settings->width;
	i = 0;
	while (i < settings->height)
	{
		j = 0;
		while (j < settings->width)
		{
			if (matrix[i][j] == settings->empty)
			{
				tmp_settings->max_size = 1;
				tmp_settings->y = i;
				tmp_settings->x = j;
				ft_echo_in_map(matrix, tmp_settings, i, j);
				if (tmp_settings->max_size > settings->max_size) {
					settings->max_size = tmp_settings->max_size;
					settings->y = tmp_settings->y;
					settings->x = tmp_settings->x;
				}

			}
			j++;
		}
		i++;
	}
	free(tmp_settings);
	printf("size: %d, y:%d, x:%d\n", settings->max_size, settings->y, settings->x);
}

// 2147483647
void ft_print_map(char *file)
{
	t_settings *settings;
	char **matrix;

	settings = (t_settings *) malloc(sizeof(t_settings));
	settings->height = 0;
	settings->width = 0;
	ft_get_settings(&settings, file);
	matrix = malloc_matrix(settings);
	fill_empty_matrix(matrix, settings);

	if (fill_matrix(matrix, settings, file) != 0)
	{
		printf("map error\n");
	}
	else
	{
		ft_print_filled_map(matrix, settings);
		ft_scan_map(matrix, settings);
		int i = 0;
		int j = 0;
		while (i < settings->max_size)
		{
			j = 0;
			while (j < settings->max_size)
			{
				matrix[settings->y + i][settings->x + j] = settings->full;
				j++;
			}
			i++;
		}

		ft_print_filled_map(matrix, settings);
	}
}

int main(int argc, char *argv[])
{
	argc = 2;
	argv[1] = "/Users/stass/_github2/BSQ/map.txt";

	int index;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			ft_print_map(argv[index]);
			index++;
		}
	}
	return 0;
}

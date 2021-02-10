#include "../include/bsq.h"

int read_and_fill(int fd, char *buffer, int **matrix, t_settings *settings)
{
	int read_bytes;
	int index_x;
	int index_y;
	int index;

	index_y = 1;
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
					return (0);
				process_map_item(buffer[index] == settings->obstacle ? 1 : 0, &index_x, &index_y, matrix);
			}
			index++;
		}
	}
	return (1);
}

int fill_matrix2(int **matrix, t_settings *settings, char *file)
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
	if (fill_matrix2(matrix, settings, file) != 0)
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


char *append_to_line(char *line, int size, char ch)
{
	char *tmp;
	int index;

	index = 0;
	tmp = (char *) malloc(sizeof(char) * size);
	while (index < size)
	{
		tmp[index] = line[index];
		index++;
	}
	if (line)
		free(line);
	index = 0;
	line = (char *) malloc(sizeof(char) * size + 1);
	while (index < size)
	{
		line[index] = tmp[index];
		index++;
	}
	line[index] = ch;
	free(tmp);
	return (line);
}

int read_settings(int fd, t_settings *settings)
{
	char *buffer;
	char *line;
	int size;

	size = 0;
	line = 0;
	buffer = (char *) malloc(sizeof(char));
	while (read(fd, buffer, 1) != 0)
	{
		if (buffer[0] == '\n')
			break;
		line = append_to_line(line, size, buffer[0]);
		size++;
	}
	free(buffer);
	if (!settings || !ft_parse_settings(&settings, line))
	{
		return (0);
	}
	return (1);
}

char *read_first_line(int fd)
{
	char *buffer;
	char *line;
	int size;

	size = 0;
	line = 0;
	buffer = (char *) malloc(sizeof(char));
	while (read(fd, buffer, 1) != 0)
	{
		if (buffer[0] == '\n')
			break;
		line = append_to_line(line, size, buffer[0]);
		size++;
	}
	free(buffer);
	return (line);
}

void fill_first_line_matrix(int **matrix, t_settings *settings, const char *line)
{
	int index_x = 0;
	int index_y = 0;
	while (index_x < settings->width)
	{
		process_map_item(line[index_x] == settings->obstacle ? 1 : 0, &index_x, &index_y, matrix);
	}
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

int read_map(int fd, t_settings *settings)
{
	char *buffer;
	int read_byte;
	char *line;
	int size;
	int **matrix;


	line = 0;
	settings = create_settings();
	if (!read_settings(fd, settings))
		return (0);
	line = read_first_line(fd);
	settings->width = ft_strlen(line);
	if (settings->width == 0)
		return (0);

	if (!(matrix = malloc_matrix(settings)))
		return (0);
	fill_empty_matrix(matrix, settings);

	fill_first_line_matrix(matrix, settings, line);

	if (!fill_matrix(matrix, settings, fd))
		return (0);
	else
	{
		ft_scan_map(matrix, settings); // ft_print_filled_map(matrix, settings);
		ft_full_map(matrix, settings);
		ft_print_filled_map(matrix, settings);
		free(settings);
//		return (1);
	}



//	size = 0;
//	buffer = (char *) malloc(sizeof(char));
//	while ((read_byte = read(fd, buffer, BYTE_COUNT)) != 0)
//	{
//		// TODO
//		ft_putstr(buffer);
//	}

	close(fd);
	return (1);
}

int main(int argc, char *argv[])
{
//	argc = 3;
//	argv[1] = "/Users/hedgi/CLionProjects/21school/BSQ/map.txt";
//	argv[2] = "/Users/hedgi/CLionProjects/21school/BSQ/map2.txt";

	int fd;
	int index;
	t_settings *settings;

	if (argc == 1)
	{
		settings = create_settings();
		if (!read_map(STDIN_FILENO, settings))
			ft_putstr("map error\n");
		free(settings);
	}
	else
	{
		index = 1;

		while (index < argc)
		{
			if ((fd = ft_try_open_file(argv[index])) < 0)
				ft_putstr("map error\n");
			else
			{
				settings = create_settings();
//		if (!read_map(STDIN_FILENO, settings)) {
//			ft_putstr("map error\n");
//		}
				if (!read_map(fd, settings))
				{
					ft_putstr("map error\n");
				}
				free(settings);
			}
//			if (ft_print_map(argv[index]) != 0)
//				ft_putstr("map error\n");
			index++;
		}

	}
	return 0;
}

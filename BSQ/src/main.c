#include "../include/bsq.h"

int read_map(int fd, t_settings *settings)
{
	char *line;
	int **matrix;

	settings = create_settings();
	if (!read_settings(fd, settings))
		return (0);
	line = read_first_line(fd);
	if ((settings->width = ft_strlen(line)) == 0 || !(matrix = malloc_matrix(settings)))
		return (0);
	fill_empty_matrix(matrix, settings);
	if (!fill_first_line_matrix(matrix, settings, line) || !fill_matrix(matrix, settings, fd))
		return (0);
	else
	{
		ft_scan_map(matrix, settings);
		ft_full_map(matrix, settings);
		ft_print_filled_map(matrix, settings);
		free(settings);
	}
	close(fd);
	return (1);
}

void read_map_from_console()
{
	t_settings *settings;

	settings = create_settings();
	if (settings)
	{
		if (!read_map(STDIN_FILENO, settings))
			ft_putstr(MAP_ERROR_MSG);
		free(settings);
	}
}

void read_map_from_files(int argc, char *argv[])
{
	int fd;
	int index;
	t_settings *settings;

	index = 1;
	while (index < argc)
	{
		if ((fd = ft_try_open_file(argv[index])) < 0)
			ft_putstr(MAP_ERROR_MSG);
		else
		{
			settings = create_settings();
			if (settings)
			{
				if (!read_map(fd, settings))
					ft_putstr(MAP_ERROR_MSG);
				free(settings);
			}
		}
		index++;
	}
}

int main(int argc, char *argv[])
{
	argc = 2;
	argv[1] = "/Users/stass/_github2/BSQ/map.txt";
//	argv[2] = "/Users/hedgi/CLionProjects/21school/BSQ/map2.txt";
//	argv[3] = "/Users/hedgi/CLionProjects/21school/BSQ/map3.txt";

	if (argc == 1)
		read_map_from_console();
	else
		read_map_from_files(argc, argv);
	return (0);
}

#include "../include/bsq.h"

int ft_try_open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	return (fd);
}

int **malloc_matrix(t_settings *settings)
{
	int index;
	int **matrix;

	matrix = (int **) malloc(sizeof(int *) * settings->height);
	index = 0;
	while (index < settings->height)
	{
		matrix[index] = (int *) malloc(sizeof(int) * settings->width);
		ft_fill_num(matrix[index], settings->width);
		index++;
	}
	return matrix;
}

void fill_empty_matrix(int **matrix, t_settings *settings)
{
	int i;
	int j;

	i = 0;
	while (i < settings->height)
	{
		j = 0;
		while (j < settings->width)
		{
			matrix[i][j] = -1;
			j++;
		}
		i++;
	}
}

t_settings *create_settings()
{
	t_settings *settings;

	settings = (t_settings *) malloc(sizeof(t_settings));
	if (settings)
	{
		settings->height = 0;
		settings->width = 0;
	}
	return settings;
}
#include "../include/bsq.h"

void ft_print_filled_map(int **matrix, t_settings *settings)
{
	unsigned long  i;
	unsigned long  j;

	i = 0;
	while (i < settings->height)
	{
		j = 0;
		while (j < settings->width)
		{
			if (matrix[i][j] == -1)
				ft_putchar(settings->full);
			else
			{
				if (matrix[i][j] == 0)
					ft_putchar(settings->obstacle);
				else
					ft_putchar(settings->empty);
			}
			j++;
		}
		free(matrix[i]);
		ft_putchar('\n');
		i++;
	}
	free(matrix);
}

void ft_scan_map(int **matrix, t_settings *settings)
{
	unsigned long  i;
	unsigned long  j;

	i = 1;
	while (i < settings->height)
	{
		j = 1;
		while (j < settings->width)
		{
			if (matrix[i][j] == -1)
			{
				matrix[i][j] = ft_get_min(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]) + 1;
				if (settings->max_size < matrix[i][j])
				{
					settings->max_size = matrix[i][j];
					settings->x = j - (matrix[i][j] - 1);
					settings->y = i - (matrix[i][j] - 1);
				}
			}
			j++;
		}
		i++;
	}
}

void process_map_item(int obstacle, unsigned long  *index_x, unsigned long  *index_y, int **matrix)
{
	if (obstacle)
		matrix[*index_y][*index_x] = 0;
	else if (*index_y == 0 || *index_x == 0)
		matrix[*index_y][*index_x] = 1;
	else
		matrix[*index_y][*index_x] = -1;
	*index_x += 1;
}

void down_vertical(unsigned long  *index_x, unsigned long  *index_y)
{
	*index_y += 1;
	*index_x = 0;
}
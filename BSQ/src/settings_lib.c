#include "../include/bsq.h"

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

int ft_get_settings(t_settings **sett, char *file)
{
	t_settings *settings;
	char *buffer;
	int fd;
	int read_bytes;
	int n_count;

	settings = *sett;
	if ((fd = ft_try_open_file(file)) < 0)
		return fd;

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

	free(buffer);
	return close(fd);
}
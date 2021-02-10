#include "../include/bsq.h"

int ft_parse_settings(t_settings **settings, char *buffer)
{
	int size;
	t_settings *sett;

	sett = *settings;
	size = ft_strlen(buffer);
	if (size < 4 || size > 13)
		return (0);
	sett->empty = buffer[size - 3];
	sett->obstacle = buffer[size - 2];
	sett->full = buffer[size - 1];
	if (sett->empty == sett->obstacle || sett->obstacle == sett->full || sett->full == sett->empty)
		return (0);
	sett->height = ft_get_num(buffer, size - 3);
	if (sett->height < 1)
		return (0);
	return (1);
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
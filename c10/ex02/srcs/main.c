#include "../includes/ft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <zconf.h>
#include <libgen.h>
#include <string.h>

int		ft_open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(basename(file));
		ft_putstr(": No such file or directory\n");
	}
	return (fd);
}

void	ft_print_error(int code)
{
	ft_putstr(strerror(code));
}

void	ft_shift_char(char *str, int str_size, int shift)
{
	int index;

	index = 0;
	while (index < str_size - shift)
	{
		str[index] = str[shift + index];
		index++;
	}
	index = 0;
	while (index < str_size - shift)
	{
		str[str_size - shift + index] = '\0';
		index++;
	}
}

void	ft_shift_str(char *str, int str_size, const char *buffer, int size)
{
	int index;
	int put_index;

	index = 0;
	put_index = 0;
	while (index < str_size && put_index < size)
	{
		if (str[index] == '\0')
		{
			str[index] = *buffer;
			buffer++;
			put_index++;
		}
		index++;
	}
	if (put_index < size)
	{
		ft_shift_char(str, str_size, size - put_index);
		ft_shift_str(str, str_size, buffer, size - put_index);
	}
}

int		ft_read_file(int fd, int count, int byte_count)
{
	int		code;
	int		read_byte;
	char	*buffer;
	char	*line;

	buffer = (char *) malloc(sizeof(char) * (byte_count));
	line = (char *) malloc(sizeof(char) * (count + 1));
	ft_fill_str(buffer, byte_count);
	ft_fill_str(line, count + 1);
	while ((read_byte = read(fd, buffer, byte_count)) != 0)
		ft_shift_str(line, count, buffer, read_byte);
	code = close(fd);
	ft_putstr(line);
	ft_putstr("\n");
	free(buffer);
	free(line);
	return (code);
}

int main(int argc, char *argv[])
{
	int fd;
	int code;
	int count;

	if (argc != 4 || ft_strcmp(argv[1], "-c") != 0 || (count = ft_get_number(argv[2])) < 0)
	{
		ft_putstr("Wrong options.\n");
		return (1);
	}
	fd = ft_open_file(argv[3]);
	if (fd >= 0)
	{
		code = ft_read_file(fd, count, count / 4);
		if (code != 0)
			ft_print_error(code);
		return (code);
	}
	return (0);
}
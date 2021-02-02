#include "../includes/ft.h"
#include <fcntl.h>
#include <zconf.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_print_error(int code)
{
	ft_putstr(strerror(code));
}

int		ft_print_content(int buff_size)
{
	char	buffer[buff_size];
	int		read_byte;

	while ((read_byte = read(STDIN_FILENO, buffer, buff_size)) != 0)
		ft_put_substr(buffer, read_byte);
	return (close(STDIN_FILENO));
}

int		ft_print_file_content(char *file, int buff_size)
{
	char	buffer[buff_size];
	int		fd;
	int		read_byte;

	ft_fill_str(buffer, buff_size);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(basename(file));
		ft_putstr(": No such file or directory\n");
		return (errno);
	}
	while ((read_byte = read(fd, buffer, buff_size)) != 0)
		ft_put_substr(buffer, read_byte);
	return (close(fd));
}

int		main(int argc, char *argv[])
{
	int index;
	int code;

	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	index = 1;
	while (index < argc)
	{
		if (ft_strcmp("-", argv[index]) == 0)
			code = ft_print_content(BYTE_COUNT);
		else
			code = ft_print_file_content(argv[index], BYTE_COUNT);
		if (code != 0)
		{
			ft_print_error(code);
			return (code);
		}
		index++;
	}
	return (0);
}
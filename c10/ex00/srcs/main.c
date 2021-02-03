#include "../includes/ft.h"
#include "../includes/ft_1.h"
#include <fcntl.h>
#include <zconf.h>

int	main(int argc, char *argv[])
{
	(void) 	argc;
	char	buffer[BYTE_COUNT];
	int		fd;
	int		read_byte;

	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		ft_fill_str(buffer, BYTE_COUNT);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (0);
		}
		while ((read_byte = read(fd, buffer, BYTE_COUNT)) != 0)
			ft_put_substr(buffer, read_byte);
		return (close(fd));
	}
	return (0);
}
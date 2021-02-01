#include "includes/ft.h"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 2)
		ft_putstr("File name missing.");
	else if (argc > 2)
		ft_putstr("Too many arguments.");

	return 0;
}

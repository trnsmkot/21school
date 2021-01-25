#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_print_char(int i_x, int i_y, int x, int y)
{
	if (i_y == 0 && i_x == 0)
		ft_putchar('/');
	else if (i_y == 0 && i_x == x - 1)
		ft_putchar('\\');
	else if (i_y == y - 1 && i_x == 0)
		ft_putchar('\\');
	else if (i_y == y - 1 && i_x == x - 1)
		ft_putchar('/');
	else if (i_x == 0 || i_y == 0 || i_x == x - 1 || i_y == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int y, int x)
{
	int i_y;
	int i_x;

	i_y = 0;
	while (i_y < y)
	{
		i_x = 0;
		while (i_x < x)
		{
			ft_print_char(i_x, i_y, x, y);
			i_x++;
		}
		ft_putchar('\n');
		i_y++;
	}
}

int main(void)
{
	rush(4, 5);
	return (0);
}

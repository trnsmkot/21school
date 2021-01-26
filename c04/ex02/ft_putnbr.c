#include <unistd.h>

int ft_up_dec(int pow)
{
	int in;

	in = 1;
	while (pow > 0)
	{
		in *= 10;
		pow--;
	}
	return in;
}

int check_print_sign(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = 147483648;
		}
	}
	return (nb);
}

void ft_putnbr(int nb)
{
	int count;
	int div;
	char ch;

	count = 0;
	div = (nb = check_print_sign(nb));
	while (div > 0)
	{
		div = div / 10;
		count++;
	}
	while (count > 0)
	{
		div = ft_up_dec(count - 1);
		ch = '0' + (nb / div);
		write(1, &ch, 1);
		nb = nb % div;
		count--;
	}
}
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

void ft_putnbr(int nb)
{
	int count;
	int div;
	char ch;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	div = nb;
	while (div > 0)
	{
		div = div / 10;
		count++;
	}
	while (count >= 0)
	{
		div = ft_up_dec(count - 1);
		ch = '0' + (nb / div);
		write(1, &ch, 1);
		nb = nb % div;
		count--;
	}
}
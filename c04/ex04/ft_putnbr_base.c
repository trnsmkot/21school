#include <unistd.h>

/**
 	◦ base is empty or size of 1;
	◦ base contains the same character twice ;
	◦ base contains + or - ;
*/
int check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == '+' || base[j] == '-' || base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void ft_putnbr_base(int nbr, char *base)
{
	int sign;
	int base_count;
	char buffer[32];
	int buff_index;

	buff_index = 32;
	sign = 1;
	if (nbr < 0)
		sign = -1;
	if ((base_count = check_base(base)))
	{
		while (nbr != 0)
		{
			buffer[buff_index] = base[sign * (nbr % base_count)];
			nbr = nbr / base_count;
			buff_index--;
		}
		if (sign < 0)
			write(1, "-", 1);
		write(1, &buffer[buff_index], 33 - buff_index );
	}
}

int main() {
	ft_putnbr_base(9876, "poneyvif");
	ft_putnbr_base(-2147483648, "0123456789");
}
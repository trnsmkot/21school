#include "../include/bsq.h"

void ft_fill_str(char *buffer, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		buffer[index] = '\0';
		index++;
	}
}

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
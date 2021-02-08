#include "../include/bsq.h"

int ft_get_num(const char *buffer, int size)
{
	int index;
	int sum;

	sum = 0;
	index = 0;
	while (index < size)
	{
		if (buffer[index] < '0' || buffer[index] > '9')
			return (0);
		sum = (sum * 10) + (buffer[index] - '0');
		index++;
	}
	return (sum);
}

int ft_get_min(int item_1, int item_2, int item_3)
{
	if (item_1 < item_2)
	{
		if (item_1 < item_3)
			return (item_1);
		else
			return (item_3);
	}
	else
	{
		if (item_2 < item_3)
			return (item_2);
		else
			return (item_3);
	}
}

void ft_fill_num(int *buffer, unsigned long size)
{
	int index;

	index = 0;
	while (index < size)
	{
		buffer[index] = -1;
		index++;
	}
}
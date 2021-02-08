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
	while (str && *str)
	{
		str++;
		count++;
	}
	return (count);
}

int ft_index_of(const char *str, char ch, int index)
{
	while (str[index] != '\0')
	{
		if (str[index] == ch)
			return (index);
		index++;
	}
	return (-1);
}

int ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	return (s1[index] - s2[index]);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
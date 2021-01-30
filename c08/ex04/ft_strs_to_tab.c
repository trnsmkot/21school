#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(const char *ch)
{
	int index;

	index = 0;
	while (ch[index] != '\0')
		index++;
	return (index);
}

void ft_copy(const char *src, char *dest)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str *stock;
	int index;
	int len;
	char *copy;

	stock = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		len = ft_strlen(av[index]);
		copy = malloc(sizeof(char) * (len + 1));
		if (copy == NULL)
		{
			free(stock);
			return (NULL);
		}
		ft_copy(av[index], copy);
		stock[index] = (struct s_stock_str) {len, av[index], copy};
		index++;
	}
	if (index == ac)
		stock[index] = (struct s_stock_str) {0, 0, 0};
	return (stock);
}
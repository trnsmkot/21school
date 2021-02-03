// malloc
#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int index;
	int *result;

	index = 0;
	result = malloc(sizeof(int) * length);
	if (result == NULL)
		return (NULL);
	while (index < length)
	{
		result[index] = f(tab[index]);
		index++;
	}

	return (result);
}
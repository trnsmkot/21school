#include <libc.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int index;

	if (min >= 0 && max > min)
	{
		*range = malloc(sizeof(int) * (max - min));
		if (range == NULL)
		{
			*range = NULL;
			return (0);
		}
		index = 0;
		while (min < max)
		{
			(*range)[index] = min;
			min++;
			index++;
		}
		return (index);
	}
	return (0);
}
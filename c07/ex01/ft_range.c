#include <libc.h>

int *ft_range(int min, int max)
{
	int *range;
	int index;

	if (min >= 0 && max > min)
	{
		range = malloc(sizeof(int) * (max - min));
		if (range == NULL)
			return (NULL);
		index = 0;
		while (min < max)
		{
			range[index] = min;
			min++;
			index++;
		}
		return (range);
	}
	return (NULL);
}
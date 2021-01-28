#include <libc.h>

char *ft_strdup(char *src)
{
	char *new_src;
	int index;

	index = 0;
	while (src[index] != '\0')
		index++;
	new_src = malloc(sizeof(*new_src) * index);
	if (new_src == NULL)
		return NULL;
	index = 0;
	while (src[index] != '\0')
	{
		new_src[index] = src[index];
		index++;
	}
	new_src[index] = '\0';
	return new_src;
}
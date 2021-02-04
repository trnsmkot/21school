#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *element;
	t_list *next_element;
	int index;

	index = 0;
	element = NULL;
	while (index < size)
	{
		next_element = ft_create_elem(strs[index]);
		if (element == NULL)
			element = next_element;
		else
		{
			next_element->next = element;
			element = next_element;
		}
		index++;
	}
	return (element);
}
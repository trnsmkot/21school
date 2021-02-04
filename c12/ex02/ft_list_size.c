#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int size;
	t_list *start_element;

	size = 0;
	start_element = begin_list;
	while (start_element != NULL)
	{
		size++;
		start_element = start_element->next;
	}
	return (size);
}
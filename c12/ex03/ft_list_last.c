#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	t_list *last_element;

	if (begin_list == NULL)
		return (begin_list);
	last_element = begin_list;
	while (last_element->next != NULL)
		last_element = last_element->next;
	return (last_element);
}
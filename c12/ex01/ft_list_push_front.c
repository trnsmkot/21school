#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;

	if (begin_list == NULL || *begin_list == NULL)
		return;
	new_element = ft_create_elem(data);
	new_element->next = *begin_list;
}
#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *element;
	t_list *last_element;

	element = ft_create_elem(data);
	if (element == NULL)
		return;
	if (*begin_list == NULL)
	{
		*begin_list = element;
		return;
	}
	last_element = *begin_list;
	while (last_element->next != NULL)
		last_element = last_element->next;
	last_element->next = element;
}
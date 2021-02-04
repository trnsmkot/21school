#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *element;

	if (begin_list == NULL)
		return;
	element = begin_list;
	while (element->next != NULL)
	{
		(*f)(element->data);
		element = element->next;
	}
	(*f)(element->data);
}
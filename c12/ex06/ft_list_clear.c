#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *pre_element;
	t_list *element;

	if (begin_list == NULL)
		return;
	element = begin_list;
	while (element->next != NULL)
	{
		pre_element = element;
		element = element->next;
		free_fct(pre_element->data);
		free(pre_element);
	}
	free_fct(element->data);
	free(element);
}
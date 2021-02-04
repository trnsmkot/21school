#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *element;
	t_list *pre_element;

	if (*begin_list == NULL)
		return;

	pre_element = NULL;
	element = *begin_list;
	while (element->next != NULL)
	{
		if (cmp(element, data_ref) == 0)
		{
			if (pre_element != NULL)
				pre_element->next = element->next;
			free_fct(element->data);
			free(element);
			element = pre_element->next;
		}
		else
		{
			element = element->next;
		}
	}
}
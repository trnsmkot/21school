#include "ft_list.h"

// (*cmp)(list_ptr->data, data_ref);
// (*free_fct)(list_ptr->data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *element;

	if (*begin_list == NULL)
		return;


	element = *begin_list;
	while (element->next != NULL)
	{
//		if (cmp(element, data_ref) == 0)
//			return (element);
		begin_list++;
	}
}
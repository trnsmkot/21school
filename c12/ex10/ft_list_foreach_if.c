#include "ft_list.h"

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list *element;

	if (begin_list == NULL)
		return;
	element = begin_list;
	while (element != NULL)
	{
		if (cmp(element, data_ref) == 0)
			f(element);
		element = element->next == NULL ? element->next : NULL;
	}
}
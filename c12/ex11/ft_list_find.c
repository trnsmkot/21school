#include "ft_list.h"

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *element;

	if (begin_list == NULL)
		return (NULL);
	element = begin_list;
	while (element != NULL)
	{
		if (cmp(element, data_ref) == 0)
			return (element);
		element = element->next == NULL ? element->next : NULL;
	}
	return (NULL);
}
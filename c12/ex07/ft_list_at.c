#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int index;
	t_list *element;

	if (begin_list == NULL)
		return (NULL);
	index = 0;
	element = begin_list;
	while (index < nbr)
	{
		if (element->next == NULL)
			return (NULL);
		element = element->next;
		index++;
	}
	return (element);
}
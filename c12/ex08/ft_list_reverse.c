#include "ft_list.h"

void ft_swap_element(t_list *element, t_list *pre_element)
{
	t_list *post_element;

	post_element = element->next;
	element->next = pre_element;
	*pre_element = *element;
	*element = *post_element;
}

void ft_list_reverse(t_list **begin_list)
{
	t_list *element;
	t_list *pre_element;

	element = *begin_list;
	if (element == NULL)
		return;
	pre_element = NULL;
	while (element->next != NULL)
	{
		if (pre_element == NULL)
		{
			pre_element = element;
			element = element->next;
			pre_element->next = NULL;
		} else
			ft_swap_element(element, pre_element);
	}
	element->next = pre_element;
	*begin_list = element;
}
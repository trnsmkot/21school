#include <stdio.h>
#include "ex10/ft_list.h"

t_list *ft_create_elem(void *data);

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;

	new_element = ft_create_elem(data);
	new_element->next = *begin_list;
	*begin_list = new_element;
}

int main()
{
//	void *data;
//	t_list *list = ft_create_elem(data);
//	printf("%p\n", list->data);

	t_list el3 = {NULL, "999"};
	t_list el2 = {&el3, "234"};
//	t_list el1 = {&el2, "123"};
//	t_list el0 = {&el1, "000"};

	t_list *list = &el2;

	ft_list_push_front(&list, "23");
	printf("%s\n", list->data);
	printf("%s\n", list->next->data);

//	t_list *list = &el0;
//	t_list **begin_list =  {list, list};
//	while (*begin_list) {
//		printf("%s\n", begin_list[0]->data);
//		begin_list++;
//	}




//	printf("%s\n", list->data);
//	ft_list_foreach(list, &set_some);
//	printf("%s\n", list->next->data);

	return 0;
}

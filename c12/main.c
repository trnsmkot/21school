#include <stdio.h>
#include "ex10/ft_list.h"

void set_some(char *str) {
	printf("%s\n", str);
}

int main()
{
//	void *data;
//	t_list *list = ft_create_elem(data);
//	printf("%p\n", list->data);

	t_list el3 = {NULL, "999"};
	t_list el2 = {&el3, "234"};
	t_list el1 = {&el2, "123"};
	t_list el0 = {&el1, "000"};


	t_list list[3] = {el0, el1, el2};

//	printf("%s\n", list->data);
//	ft_list_foreach(list, &set_some);
//	printf("%s\n", list->next->data);

	return 0;
}

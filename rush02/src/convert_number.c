#include "../includes/rush.h"
#include <libc.h>

char *find_value_from_dict(d_number *dictionary, int num, int range_size, int is_100)
{
	d_number *item;

	item = dictionary;
	while (item)
	{
		if (range_size > 1 && item->size == range_size)
		{
			printf("%s ", item->value);
		}

		if (item->size == 1 && item->ranges[0] == num)
		{
			if (range_size  == 1 || num != 0)
				printf("%s ", item->value);
		}
		if (is_100 && item->size == 1 && item->ranges[0] == 100)
		{
			printf("%s ", item->value);
		}

		item = item->next;
	}
	return (0);
}

void add_print_number_back(d_str **list, d_number *dictionary, int num, int range_size, int is_100)
{
	d_str *element;
	d_str *last_element;
	char *value;

	value = find_value_from_dict(dictionary, num, range_size, is_100);
	if (!value)
		return;
	if (!(element = create_str_elem(value, 0, ft_strlen(value))))
		return;
	if (!(*list))
	{
		*list = element;
		return;
	}
	last_element = *list;
	while (last_element->next != 0)
		last_element = last_element->next;
	last_element->next = element;
}

d_str *convert_number(d_number *dictionary, d_number *number)
{
	d_str *element;
	int index;
	int num;


	index = 0;
	while (index < number->size)
	{
		num = number->ranges[index];

		if (num / 100 > 0)
		{
			add_print_number_back(&element, dictionary, num / 100, number->size - index, 1);
		}

		if ((num % 100 / 10) * 10 > 19)
		{
			add_print_number_back(&element, dictionary, (num % 100 / 10) * 10, number->size - index, 0);
			if (num % 10 > 0)
				add_print_number_back(&element, dictionary, num % 10, number->size - index, 0);
		}
		else
		{
			if (num % 10 > 0 || (number->size == 1 && num == 0))
				add_print_number_back(&element, dictionary, num % 100, number->size - index, 0);
		}

		index++;
	}

	// разложить по простым цыфрам и искать их в словаре



//	element = dictionary;
//	while (element)
//	{
//
//		element = element->next;
//	}
	return (0);
}
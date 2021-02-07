
#include "../includes/rush.h"

d_number *parse_number(char *num)
{
	d_number *number;

	number = (d_number *) malloc(sizeof(d_number));
	if (number)
	{
		number->next = 0;
		number->size = 0;
		number->value = num;
		number->key = num;
		convert_str_t_ranges(&number);
	}
	return (number);
}
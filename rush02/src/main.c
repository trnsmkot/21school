#include "../includes/rush.h"


int main(int argc, char *argv[])
{
	char *dict_path;
	char *num_as_string;
	d_number *dictionary;
	d_number *number;

	// FIXME
	argc = 2;
	argv[1] = "123";

	if (argc < 2)
		return (0);
	dict_path = (argc > 2) ? argv[1] : DEFAULT_DICT_PATH;
	num_as_string = (argc > 2) ? argv[2] : argv[1];
	number = parse_number(num_as_string);
	if (number)
		if ((dictionary = parse_dictionary(dict_path)))
		{
			if (!convert_number(dictionary, number))
				write(1, "Dict Error\n", 11);
		}
		else
			write(1, "Dict Error\n", 11);
	else
		write(1, "Error\n", 6);
	return 0;
}
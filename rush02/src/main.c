#include "../includes/rush.h"


int main(int argc, char *argv[])
{
	char *dict_path;
	char *num_as_string;
	d_str *result;
	d_number *dictionary;
	d_number *number;

	// FIXME
	argc = 2;
	argv[1] = "1001023";

	if (argc < 2)
		return (0);
	dict_path = (argc > 2) ? argv[1] : DEFAULT_DICT_PATH;
	num_as_string = (argc > 2) ? argv[2] : argv[1];
	number = parse_number(num_as_string);
	if (number)
		if ((dictionary = parse_dictionary(dict_path)))
		{
			if ((result = convert_number(dictionary, number)))
				result; // PRINT
			else
				ft_putstr("Dict Error\n");
		}
		else
			ft_putstr("Dict Error\n");
	else
		ft_putstr("Error\n");
	return 0;
}
/**
 * Create a program that displays its given arguments sorted by ascii order.
 * One argument per line
 */
#include <unistd.h>

void swap(char **left, char **right)
{
	char *tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

int is_left_greater(char *left, char *right)
{
	int index;

	index = 0;
	while (left[index] != '\0' && right[index] != '\0')
	{
		if (left[index] > right[index])
			return (1);
		index++;
	}
	return (0);
}

void sort_argv(char **argv[], int idx, int size)
{
	int index;
	int was_swap;

	was_swap = 0;
	index = 1;
	while (index < size - 2)
	{
		if (is_left_greater(*argv[index], *argv[index]))
		{
//			swap(argv[index], argv[index + 1]);
//			was_swap = 1;
		}
		index++;
	}
//	if (was_swap)
//		sort_argv(argv, idx, size);
}

int main(int argc, char *argv[])
{
	int index;
	int arg_index;

	if (argc < 2)
		return (0);
	arg_index = 1;
	sort_argv(&argv, arg_index, argc);
	while (arg_index < argc)
	{
		index = 0;
		while (argv[arg_index][index] != '\0')
		{
			write(1, &argv[arg_index][index], 1);
			index++;
		}
		write(1, "\n", 1);
		arg_index++;
	}
	return (0);
}
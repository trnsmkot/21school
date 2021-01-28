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
		else if (left[index] == right[index])
			index++;
		else
			return (0);
	}
	if (left[index] != '\0' && right[index] == '\0')
		return (1);
	return (0);
}

int sort_argv(char **argv, int index, int size)
{
	int was_swap;

	was_swap = 0;
	while (index < size - 1)
	{
		if (is_left_greater(argv[index], argv[index + 1]))
		{
			swap(&argv[index], &argv[index + 1]);
			was_swap = 1;
		}
		index++;
	}
	return (was_swap);
}

int main(int argc, char *argv[])
{
	int index;
	int arg_index;
	int need_sort;

	if (argc < 2)
		return (0);
	arg_index = 1;
	need_sort = 1;
	while (need_sort)
		need_sort = sort_argv(argv, 1, argc);
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
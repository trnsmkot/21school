/**
 * Create a program that displays its given arguments sorted by ascii order.
 * One argument per line
 */
#include <unistd.h>

int main(int argc, char *argv[])
{
	int index;
	int arg_index;

//	if (argc > 1)
//	{
//		arg_index = 1;
//		while (arg_index < argc)
//		{
//			index = 0;
//			while (argv[arg_index][index] != '\0')
//			{
//				write(1, &argv[arg_index][index], 1);
//				index++;
//			}
//			write(1, "\n", 1);
//			arg_index++;
//		}
//	}

	write(1, "\n", 1);
	return (0);
}
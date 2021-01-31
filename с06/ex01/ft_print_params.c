#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int index;
	int arg_index;

	printf("(%s)", argv[1]);

	if (argc > 1)
	{
		arg_index = 1;
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
	}
	return (0);
}
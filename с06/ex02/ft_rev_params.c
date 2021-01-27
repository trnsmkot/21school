/**
 We’re dealing with a program here, you should therefore have a function main in your .c file.
• Create a program that displays its given arguments.
• One per line, in the reverse order of the command line.
• It should display all arguments, except for argv[0].
 */
#include <unistd.h>

int main(int argc, char *argv[])
{
	int index;
	int arg_index;

	if (argc > 1)
	{
		arg_index = argc - 1;
		while (arg_index > 0)
		{
			index = 0;
			while (argv[arg_index][index] != '\0')
			{
				write(1, &argv[arg_index][index], 1);
				index++;
			}
			write(1, "\n", 1);
			arg_index--;
		}
	}
	return (0);
}
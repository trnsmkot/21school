#include <unistd.h>

int main(int argc, char *argv[])
{
	int index;

	if (argc < 1)
	{
		write(1, "Illegal state error", 19);
		return (0);
	}
	index = 0;
	while (argv[0][index] != '\0')
	{
		write(1, &argv[0][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
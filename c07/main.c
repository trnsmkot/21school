#include <stdio.h>

char *ft_strdup(char *src);

int main()
{
	char *str = "sdfdsfd";
	printf("%p\n", str);

	char *new = ft_strdup("0123456789");
	printf("%p - \"%s\"\n", new, new);
	return 0;
}
//
//int main(int argc, char **argv) {
//
//	printf("%s", argv[0]);
//	return (0);
//}

#include <stdio.h>

char *ft_strdup(char *src);

int *ft_range(int min, int max);

int ft_ultimate_range(int **range, int min, int max);

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
//	char *str = "sdfdsfd";
//	printf("%p\n", str);
//
//	char *new = ft_strdup("0123456789");
//	printf("%p - \"%s\"\n", new, new);

//	int arr[5] = {1, 2, 3, 4, 5};
//
//	int *p;
//	p = &arr[0];
//
//	int max = 10;
//	int min = 5;
//	int *range = ft_range(min, max);

//	int *range2[] = NULL;

//	while (*p)
//	{
//		printf("%d ", *p);
//		p++;
//	}

//	if (range == NULL)
//	{
//		printf("NULL");
//	} else
//	{
//		int index = 0;
//		while (index < max - min)
//		{
//			printf("%d ", range[index]);
//			index++;
//		}
//	}

//	int *range;
//	int range_size = ft_ultimate_range(&range, 5, 30);
////	printf("%d", range_size);
//	if (range == NULL)
//	{
//		printf("NULL");
//	} else
//	{
//		int index = 0;
//		while (index < range_size)
//		{
//			printf("%d ", range[index]);
//			index++;
//		}
//	}

	char *string[] = {"123", "456", "789"};
	char *str = ft_strjoin(3, string, "|");
	printf("%s", str);
//	printf("\n");

	return 0;
}
//
//int main(int argc, char **argv) {
//
//	printf("%s", argv[0]);
//	return (0);
//}

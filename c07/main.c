#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
	{
		return (NULL);
	}
	else
		i = -1;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


int main()
{
//	char *str = "sdfdsfd";
//	printf("%p\n", str);
//
	char *new = ft_strdup("0123456789");
	printf("%s ", new);
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

//	while (*new)
//	{
//		printf("%d ", *new);
//		new++;
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

//	char *string[] = {"123", "456", "789"};
//	char *str = ft_strjoin(3, string, "|");
//	printf("%s", str);
//	printf("\n");

	return 0;
}
//
//int main(int argc, char **argv) {
//
//	printf("%s", argv[0]);
//	return (0);
//}

#include <stdio.h>
#include <libc.h>

void ft_foreach(int *tab, int length, void(*f)(int));
int *ft_map(int *tab, int length, int(*f)(int));
//int ft_any(char **tab, int(*f)(char *));
int ft_is_sort(int *tab, int length, int(*f)(int, int));

void ft_putnbr(int num)
{
	char ch;

	ch = '0' + num;
	write(1, &ch, 1);
}

int ft_putnbr2(int num)
{
	char ch;

	ch = '0' + num;
	write(1, &ch, 1);
	return num;
}

int ft_check_str(char *str)
{
//	int index = 0;
//	while (str[index] != '\0')
//	{
//		if (str[index] == '1')
//		{
//			return (1);
//		}
//		index++;
//	}
	return (0);
}

int ft_check_sort(int left, int right)
{
	if (left < right) {
		return (-1);
	}
	return (0);
}

int	ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i++]))
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	char *tab[2] = {"abc", "223"};
	printf("%d", ft_any(tab, &ft_check_str));

//	argv[1] = 42amis
//	argv[2] = -
//	argv[3] = --+-20toto12


//	int tab[5] = {1, 2, 3, 4, 5};
//	ft_foreach(tab, 5, &ft_putnbr);
//	int *tab1 = ft_map(tab, 5, &ft_putnbr2);

//	ft_foreach(ft_map(tab, 5, &ft_putnbr2), 5, &ft_putnbr);
//	char *tab[3] = {"abc", "123"};

//	int tab[5] = {2, 2, 3, 4, 5};
//	int tab[5] = {5, 3, 2, 1, 1};
//	printf("%d", ft_is_sort(tab, 5, &ft_check_sort));

	return 0;
}

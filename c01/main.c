#include <stdio.h>
#include "ex00/ft_ft.h"
#include "ex01/ft_ultimate_ft.h"
#include "ex02/ft_swap.h"
#include "ex03/ft_div_mod.h"
#include "ex04/ft_ultimate_div_mod.h"
#include "ex05/ft_putstr.h"
#include "ex06/ft_strlen.h"
#include "ex07/ft_rev_int_tab.h"
#include "ex08/ft_sort_int_tab.h"

int main()
{
//	int num = 2;
//	ft_ft(&num);
//	printf("ex00: %d\n", num);

//	int ********num2;
//	ft_ultimate_ft(&num2);
//	printf("ex01: %d\n", ********num2);

//	int a = 10;
//	int b = 20;
//	ft_swap(&a, &b);
//	printf("ex02: %d - %d", a, b);

//	int a = 11;
//	int b = 3;
//	int div;
//	int mod;
//	ft_div_mod(a, b, &div, &mod);
//	printf("ex02: %d - %d", div, mod);

//	int a = 13;
//	int b = 4;
//	ft_ultimate_div_mod(&a, &b);
//	printf("ex02: %d - %d", a, b);
//
//	char *str = "234sdfpppp652560";
//	ft_putstr(str);

//	char *str = "234sdf34";
//	int count = ft_strlen(str);
//	printf("ex06: %d", count);

//	int tab[] = {1, 10, 123, 3, 11};
//	for (int i = 0; i < 5; ++i)
//	{
//		printf("%d ", tab[i]);
//	}
//	printf("\n");
//	ft_rev_int_tab(tab, 5);
//	for (int i = 0; i < 5; ++i)
//	{
//		printf("%d ", tab[i]);
//	}

	int tab[] = {1, 10, 123, 3, 11};
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
	ft_sort_int_tab(tab, 5);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", tab[i]);
	}

	return 0;
}
//
//int main()
//{
//	return 0;
//}


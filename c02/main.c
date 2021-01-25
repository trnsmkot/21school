#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcpy.h"
#include "ex01/ft_strncpy.h"
#include "ex02/ft_str_is_alpha.h"
#include "ex03/ft_str_is_numeric.h"
#include "ex04/ft_str_is_lowercase.h"
#include "ex05/ft_str_is_uppercase.h"
#include "ex06/ft_str_is_printable.h"
#include "ex07/ft_strupcase.h"
#include "ex08/ft_strlowcase.h"
#include "ex09/ft_strcapitalize.h"
#include "ex10/ft_strlcpy.h"
#include "ex11/ft_putstr_non_printable.h"
#include "ex12/ft_print_memory.h"

int main()
{
//	char *str = "string example";
//	char dest[80];
//	ft_strcpy(dest, str);
//	strcpy(dest, str);
//	printf("ex00: |%s|", dest);

	char *src = "aaa";
	char dest[11] = "0123456789";
//	printf("sizeof: %d\n", sizeof(dest) - 1);
//	strncpy(dest, str, 4);
	printf("%s\n", dest);
	ft_strncpy(dest, src, 5);


	printf("ex00: |%s|", dest);
//	printf("-7:%i|", dest[7]);
//	printf("-8:%i|", dest[8]);
//	printf("lu: |%lu|", sizeof(dest));
//	char str[15] = "adsfsdfSDdfdf";
//	char *des = ft_strupcase(str);
//	printf("|ex02: %s", des);


//	char *str = "2323";
//	int in = ft_str_is_printable(str);
//	printf("\nex06: %d", in);
//	char str[101] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//	char *up = ft_strcapitalize(str);
//	printf("ex08: %s", up);


	return 0;
}

#include <stdio.h>

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

int main()
{

//	int i = 2;
//	printf("%d\n", ft_iterative_factorial(i));
//	printf("%d\n", ft_iterative_power(0, 0));
//	printf("%d\n", ft_iterative_power(i, -10));
//	printf("%d\n", ft_iterative_power(i, 10));

	// 0, 1, 1, 2, 3, 5, 8, 13,     21, 34, 55, 89
	// index 7 == 13
//	printf("%d\n", ft_fibonacci(40));
//	printf("%d\n", ft_sqrt(31 * 30));

//	printf("%d\n", ft_is_prime(2147483647));

//  ex - 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131
	printf("%d\n", ft_find_next_prime(3));

	return 0;
}

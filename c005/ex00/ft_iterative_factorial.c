/**
 • Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
 • If the argument is not valid the function should return 0.
 • Overflows must not be handled, the function return will be undefined.
 * */
int ft_iterative_factorial(int nb)
{
	int fact;

	fact = nb < 0 ? 0 : 1;
	while (nb > 0 && fact > 0)
	{
		fact *= nb;
		nb--;
	}
	return (fact);
}
/**
 • Create a recursive function that returns the factorial of the number given as a parameter.
 • If the argument is not valid the function should return 0.
 • Overflows must not be handled, the function return will be undefined.
 */
int ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
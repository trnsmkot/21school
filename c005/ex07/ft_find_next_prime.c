/**
 Create a function that returns the next prime number greater or equal to the number given as argument.
 */
int is_prime(int nb)
{
	int index;

	if (nb < 2)
		return (0);
	index = 2;
	while (index < (nb / 2 + 1))
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	int num;

	num = nb < 2 ? 2 : nb;
	while (num < 2147483647)
	{
		if (is_prime(num))
			return (num);
		num++;
	}
	return (num);
}
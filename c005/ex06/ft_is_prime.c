/**
 Create a function that returns 1 if the number given as a parameter is a prime number, and 0 if it isn’t.
 0 and 1 are not prime numbers.

 ex - 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131
 */
int ft_is_prime(int nb)
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
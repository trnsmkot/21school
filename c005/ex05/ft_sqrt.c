/**
 Create a function that returns the square root of a number (if it exists), or 0 if the
 square root is an irrational number.
 */
int ft_sqrt(int nb)
{
	int result;
	int it;

	result = 0;
	it = 0;
	while (result < nb && nb > 0)
	{
		result = it * it;
		if (result == nb)
			return (it);
		it++;
	}
	return (0);
}
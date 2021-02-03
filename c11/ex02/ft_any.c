int ft_any(char **tab, int(*f)(char *))
{
	int index;

	index = 0;
	while (tab[index])
	{
		if (f(tab[index]) != 0)
			return (1);
		index++;
	}
	return (0);
}
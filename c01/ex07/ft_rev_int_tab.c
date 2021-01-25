void ft_rev_int_tab(int *tab, int size)
{
	int new_tab[size];
	int index;

	index = 0;
	while (index < size)
	{
		new_tab[index] = tab[size - index - 1];
		index++;
	}
	*tab = *new_tab;
}
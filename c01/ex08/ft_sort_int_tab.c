void ft_n_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void ft_sort_int_tab(int *tab, int size)
{
	int need_sort;
	int index;

	need_sort = 1;
	while (need_sort > 0)
	{
		index = 0;
		need_sort = 0;
		while (index < size - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				need_sort = 1;
				ft_n_swap(&tab[index], &tab[index + 1]);
			}
			index++;
		}
	}
}
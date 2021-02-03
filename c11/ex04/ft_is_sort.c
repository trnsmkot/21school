int check_desc_order(int left, int right, int *is_shift, int *direct)
{
	if (*is_shift == 0 && left != right)
	{
		*direct = -1;
		*is_shift = 1;
	}
	else if (left != right && *direct == 0)
		return (0);
	return (1);
}

int check_asc_order(int *is_shift, int *direct)
{
	if (*is_shift > 0 && *direct == -1)
		return (0);
	else
	{
		*direct = 0;
		*is_shift = 1;
	}
	return (1);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int index;
	int direct;
	int is_shift;

	index = 0;
	direct = -1;
	is_shift = 0;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) == 0)
		{
			if (check_desc_order(tab[index], tab[index + 1], &is_shift, &direct) == 0)
				return (0);
		}
		else
		{
			if (check_asc_order(&is_shift, &direct) == 0)
				return (0);
		}
		index++;
	}
	return (1);
}
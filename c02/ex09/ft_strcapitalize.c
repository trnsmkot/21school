char *ft_strcapitalize(char *str)
{
	int i;
	int start;

	i = 0;
	start = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'z')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				if (start)
					str[i] -= 32;
			start = 0;
		} else
			start = 1;
		if (str[i] >= '0' && str[i] <= '9')
			start = 0;
		i++;
	}
	return (str);
}
int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str && *str)
	{
		str++;
		count++;
	}
	return (count);
}
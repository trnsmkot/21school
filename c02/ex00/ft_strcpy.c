char *ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (*src)
	{
		dest[index] = *src;
		src++;
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
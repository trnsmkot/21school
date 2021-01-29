#include <libc.h>

int get_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int copy_substr(const char *str, char *dest, int dindex)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		dest[dindex] = str[index];
		dindex++;
		index++;
	}
	return (dindex);
}

void copy_str(int size, char **strs, const char *sep, char *dest)
{
	int index;
	int str_size;

	index = 0;
	str_size = 0;
	while (index < size)
	{
		str_size = copy_substr(strs[index], dest, str_size);
		if (index < size - 1)
			str_size = copy_substr(sep, dest, str_size);
		index++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int index;
	int sep_size;
	int str_size;
	char *str;

	if (size < 1)
		return ("");
	sep_size = get_strlen(sep);
	index = 0;
	str_size = 0;
	while (index < size)
	{
		str_size += get_strlen(strs[index]);
		index++;
	}
	str = malloc(sizeof(char) * (str_size + sep_size * (size - 1)) + 1);
	copy_str(size, strs, sep, str);
	return (str);
}
/**
 	◦ base is empty or size of 1;
	◦ base contains the same character twice ;
	◦ base contains + or - or whitespaces;
*/
int is_isspace(char ch)
{
	char *line;
	int index;

	index = 0;
	line = "\t\n\v\f\r ";
	while (line[index] != '\0')
	{
		if (line[index] == ch)
			return (1);
		index++;
	}
	return (0);
}

int check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == '+' || base[j] == '-' || is_isspace(base[j]) || base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int is_base(char *base, char ch)
{
	int index;

	index = 0;
	while (base[index] != '\0')
	{
		if (ch == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int get_pow(int num, int pow)
{
	int result;

	result = 1;
	while (pow > 0)
	{
		result = result * num;
		pow--;
	}
	return (result);
}

int calc_buffer(const int buffer[], int count, int index)
{
	int buff;
	int index2;

	index2 = 0;
	buff = 0;
	while (index > 0)
	{
		buff += buffer[index2] * get_pow(count, index - 1);
		index2++;
		index--;
	}
	return (buff);
}

int ft_atoi_base(char *str, char *base)
{
	int base_count;
	int index;
	int index_base;
	int buffer[32] = {};

	index = 0;
	if ((base_count = check_base(base)))
	{
		while (str[index] != '\0')
		{
			if ((index_base = is_base(base, str[index])) >= 0)
				buffer[index] = index_base;
			else
				break;
			index++;
		}
		return (calc_buffer(buffer, base_count, index));
	}
	return (0);
}



/**
• Write a function that converts the initial portion of the string pointed by str to its int representation
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
• Your function should read the string until the string stop following the rules and return the number found until now.
• You should not take care of overflow or underflow. result can be undefined in that case.
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

int is_plusmunus(char ch)
{
	if (ch == '+')
		return (1);
	else if (ch == '-')
		return (-1);
	else
		return (0);
}

int is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return (-1);
}

int get_number(char *str, int index)
{
	int num;
	int sum;

	sum = 0;
	while (str[index] != '\0')
	{
		num = is_number(str[index]);
		if (num >= 0)
			sum = sum * 10 + num;
		else
			return (sum);
		index++;
	}
	return (sum);
}

int ft_atoi(char *str)
{
	int index;
	int is_space;
	int is_sign;
	int sign;

	index = 0;
	sign = 1;
	is_space = 1;
	while (str[index] != '\0')
	{
		if (is_space)
			is_space = is_isspace(str[index]);
		else
		{
			is_sign = is_plusmunus(str[index]);
			if (is_sign == 0)
				return (sign * get_number(str, index));
			else
				sign *= is_sign;
		}
		index++;
	}
	return (0);
}
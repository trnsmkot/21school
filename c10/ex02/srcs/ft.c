/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:15:15 by stass             #+#    #+#             */
/*   Updated: 2021/02/02 23:15:17 by stass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_fill_str(char *buffer, int size)
{
	int count;

	count = 0;
	while (count < size)
	{
		buffer[count] = '\0';
		count++;
	}
}

int		ft_get_number(char *num) {
	int index;
	int sum;
	int size;

	index = 0;
	sum = 0;
	size = ft_strlen(num) - 1;
	while (num[index] != '\0')
	{
		if (num[index] >= '0' && num[index] <= '9')
		{
			sum += (num[index] - '0');
			sum *= (size - index > 0) ? 10 : 1;
		}
		else
			return (-1);
		index++;
	}
	return (sum);
}

void	ft_shift_char(char *str, int str_size, int shift)
{
	int index;

	index = 0;
	while (index < str_size - shift)
	{
		str[index] = str[shift + index];
		index++;
	}
	index = 0;
	while (index < str_size - shift)
	{
		str[str_size - shift + index] = '\0';
		index++;
	}
}

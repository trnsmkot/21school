/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <stass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29.04.2021 19:06:29 by stass             #+#    #+#             */
/*   Updated: 29.04.2021 19:06:29 by stass            #+#   #+#+#+#+.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	if (!b)
		return (NULL);
	index = 0;
	while (index < len)
	{
		*(unsigned char *)(b + index) = (unsigned char)c;
		index++;
	}
	return (b);
}

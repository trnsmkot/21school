/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <stass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01.05.2021 10:58:20 by stass             #+#    #+#             */
/*   Updated: 01.05.2021 10:58:20 by stass            #+#   #+#+#+#+.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;

	if (dst && src)
	{
		index = 0;
		while (index < n)
		{
			*(unsigned char *)(dst + index) = *(unsigned char *)(src + index);
			if (*(unsigned char *)(src + index) == (unsigned char)c)
				return (dst + index + 1);
			index++;
		}
	}
	return (NULL);
}
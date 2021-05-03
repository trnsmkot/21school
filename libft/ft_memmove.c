/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <stass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01.05.2021 11:14:49 by stass             #+#    #+#             */
/*   Updated: 01.05.2021 11:14:49 by stass            #+#   #+#+#+#+.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	if (!dst || !src)
		return (NULL);
	if (dst == src || len == 0)
		return (dst);
	ch_dst = (unsigned char *)dst;
	ch_src = (unsigned char *)src;
	if (ch_dst <= ch_src)
		while (len--)
			*ch_dst++ = *ch_src++;
	else
	{
		ch_dst += len;
		ch_src += len;
		while (len--)
			*--ch_dst = *--ch_src;
	}
	return (dst);
}

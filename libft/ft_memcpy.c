/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stass <stass@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01.05.2021 10:44:09 by stass             #+#    #+#             */
/*   Updated: 01.05.2021 10:44:09 by stass            #+#   #+#+#+#+.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	if (!dst || !src)
		return (NULL);
	ch_dst = (unsigned char *)dst;
	ch_src = (unsigned char *)src;
	while (n--)
		*ch_dst++ = *ch_src++;
	return (dst);
}

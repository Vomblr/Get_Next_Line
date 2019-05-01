/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:03:04 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/16 12:32:15 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;
	size_t				i;

	p_dst = (unsigned char*)dst;
	p_src = (const unsigned char*)src;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_dst[i] == c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}

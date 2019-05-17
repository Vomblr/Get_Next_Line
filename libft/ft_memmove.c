/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:50:26 by Dmitry            #+#    #+#             */
/*   Updated: 2019/05/16 21:53:24 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (!dst && !src && len == 0)
		return (NULL);
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (p_dst < p_src)
		while (len--)
			*p_dst++ = *p_src++;
	else
	{
		p_src = p_src + (len - 1);
		p_dst = p_dst + (len - 1);
		while (len--)
			*p_dst-- = *p_src--;
	}
	return (dst);
}

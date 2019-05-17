/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:17:30 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/15 19:38:25 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	char	*p2;
	char	*res;

	if (!s || !f ||
				!(res = (char*)ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	p = (char*)s;
	p2 = res;
	while (*p)
		*p2++ = f(*p++);
	return (res);
}

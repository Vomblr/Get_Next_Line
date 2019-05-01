/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:35:20 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/18 15:59:32 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (len == (size_t)(-1))
		return (NULL);
	if (!(res = (char*)ft_memalloc(len + 1)) || !s)
		return (NULL);
	res = ft_strncpy(res, (char*)s + start, len);
	return (res);
}

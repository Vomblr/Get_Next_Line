/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:55:40 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/15 16:36:41 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	pos;
	size_t	i;

	if (!*needle)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && pos < len)
	{
		if (str[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && str[pos + i] == needle[i]
					&& (pos + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (NULL);
}

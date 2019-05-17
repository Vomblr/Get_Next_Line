/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:06:02 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/15 16:26:23 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	size_t	pos;
	size_t	i;

	if (!*needle)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && str[pos + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:48:10 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/15 19:02:52 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		return (NULL);
	len = ft_strlen(src);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

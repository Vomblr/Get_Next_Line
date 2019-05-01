/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:14:28 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/15 16:01:05 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	while (*str)
	{
		if (*str == sym)
			return ((char*)str);
		str++;
	}
	if (sym == '\0')
		return ((char*)str);
	return (NULL);
}

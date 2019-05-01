/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:58:47 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/15 16:11:19 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	char *last_pos;

	last_pos = (0);
	while (*str)
	{
		if (*str == sym)
			last_pos = (char*)str;
		str++;
	}
	if (last_pos)
		return (last_pos);
	if (sym == '\0')
		return ((char*)str);
	return (NULL);
}

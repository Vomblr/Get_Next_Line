/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:09:06 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/16 20:13:08 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(char *s1, char *s2, size_t s)
{
	if (s == 1 || s == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (s == 2 || s == 3)
	{
		free(s2);
		s2 = NULL;
	}
}

char		*ft_strjoinfree(char *s1, char *s2, size_t s)
{
	char	*res;
	size_t	size;

	size = 0;
	if (s1 && s2)
		size = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		size = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		size = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (s1)
		res = ft_strcpy(res, (char*)s1);
	else
		res = ft_strcpy(res, (char*)s2);
	if (s1 && s2)
		res = ft_strcat(res, (char*)s2);
	free_str(s1, s2, s);
	return (res);
}

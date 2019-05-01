/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:56:11 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/25 21:01:39 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	if (!(copy = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(copy, s1, n);
	copy[n] = '\0';
	return (copy);
}

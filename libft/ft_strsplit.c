/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:08 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/18 16:13:07 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wlen(char const *s, char delimiter)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == delimiter)
		i++;
	while (s[i] && s[i] != delimiter)
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	ind;

	i = -1;
	ind = 0;
	if (!s || !(split = (char**)malloc(sizeof(char*) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	while (++i < ft_wrdcnt(s, c))
	{
		if (!(split[i] = (char*)malloc(sizeof(char) * (wlen(&s[ind], c) + 1))))
		{
			free(split);
			return (NULL);
		}
		j = 0;
		while (s[ind] == c)
			ind++;
		while (s[ind] != c && s[ind])
			split[i][j++] = s[ind++];
		split[i][j] = '\0';
	}
	split[i] = NULL;
	return (split);
}

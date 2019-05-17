/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:36:46 by Dmitry            #+#    #+#             */
/*   Updated: 2019/04/16 15:38:32 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - j] == ' ' || s[len - j] == '\n' || s[len - j] == '\t')
		j++;
	if (i == 0 && j == 0)
		return (ft_strdup(s));
	if (i == len + 1)
		return (ft_memalloc(1));
	if (!(str = ft_strsub(s, i, len - i - j + 1)))
		return (NULL);
	return (str);
}

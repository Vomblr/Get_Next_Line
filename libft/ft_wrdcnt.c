/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:26:35 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/17 19:27:11 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wrdcnt(char const *s, char delimiter)
{
	size_t		word_count;
	size_t		next_word_flg;
	size_t		i;

	word_count = 0;
	next_word_flg = 1;
	i = 0;
	while (s[i])
	{
		if (next_word_flg && s[i] != delimiter)
		{
			word_count++;
			next_word_flg = 0;
		}
		if (s[i] == delimiter)
			next_word_flg = 1;
		i++;
	}
	return (word_count);
}

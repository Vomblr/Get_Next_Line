/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:21:34 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/16 18:31:18 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_size(int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == I_MIN)
		return (ft_strdup("-2147483648"));
	if ((sign = n) < 0)
		n = -n;
	if (!(res = (char*)malloc(sizeof(char) * (n_size(n) + 1))))
		return (NULL);
	i = 0;
	res[i++] = n % 10 + '0';
	while ((n /= 10) > 0)
		res[i++] = n % 10 + '0';
	if (sign < 0)
		res[i++] = '-';
	res[i++] = '\0';
	return (ft_strrev(res));
}

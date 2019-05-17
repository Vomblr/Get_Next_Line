/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:14:49 by Dmitry            #+#    #+#             */
/*   Updated: 2019/05/16 18:30:50 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skiptabs(char *str)
{
	while (*str == ' ' ||
			*str == '\n' ||
			*str == '\t' ||
			*str == '\v' ||
			*str == '\f' ||
			*str == '\r')
		str++;
	return (str);
}

static int	check_long(int sign, unsigned long res, char c)
{
	if (sign > 0 && (res > L_MAX / 10 ||
		(res == L_MAX / 10 && (unsigned long)(c - '0') > L_MAX % 10)))
		return (-1);
	else if (sign < 0 && (res > L_MAX / 10 ||
		(res == L_MAX / 10 &&
		(unsigned long)(c - '0') > (L_MAX % 10 + 1))))
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int					sign;
	unsigned long		res;

	sign = 1;
	res = 0;
	str = skiptabs((char*)str);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (check_long(sign, res, *str) == -1)
			return (-1);
		else if (check_long(sign, res, *str) == 0)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

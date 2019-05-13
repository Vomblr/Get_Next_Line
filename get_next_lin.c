/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:17:58 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/13 13:35:00 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	*read_line(const int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	int		size;

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (0);
	if (str == NULL)
		str = ft_strnew(1);
	while (!(ft_strchr(str, '\n')))
	{
		if ((size = read(fd, buff, BUFF_SIZE)) < 0)
			return (0);
		buff[size] = '\0';
		str = ft_strjoinfree(str, buff, 1);
		if (str[0] == '\0' || size == 0)
			break ;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	t_line		list;

	if (!(str = read_line(fd, str)) || !line)
		return (-1);
	if ((list.content = ft_strchr(str, '\n')) > 0)
	{
		list.size = list.content - str;
		if (!(*line = ft_strndup(str, list.size)))
			return (-1);
		free(str);
		str = ft_strdup(list.content + 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}

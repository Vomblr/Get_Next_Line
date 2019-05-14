/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:17:58 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/14 15:14:02 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	*read_line(int fd, char **str)
{
	char	buff[BUFF_SIZE + 1];
	int		size;

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (0);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while (!(ft_strchr(str[fd], '\n')))
	{
		if ((size = read(fd, buff, BUFF_SIZE)) < 0)
			return (0);
		buff[size] = '\0';
		str[fd] = ft_strjoinfree(str[fd], buff, 1);
		if (str[fd][0] == '\0' || size == 0)
			break ;
	}
	return (str[fd]);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[1000];
	t_line		list;

	if (!(str[fd] = read_line(fd, str)) || !line)
		return (-1);
	if ((list.content = ft_strchr(str[fd], '\n')) > 0)
	{
		list.size = list.content - str[fd];
		if (!(*line = ft_strndup(str[fd], list.size)))
			return (-1);
		free(str[fd]);
		str[fd] = ft_strdup(list.content + 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}

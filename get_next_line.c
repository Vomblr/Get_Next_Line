/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:05:52 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/17 16:04:38 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	write_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	t_line		lin;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while ((lin.ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[lin.ret] = '\0';
		if (!str[fd])
			str[fd] = (char*)ft_memalloc(1);
		lin.tmp = ft_strjoinfree(str[fd], buff, 1);
		str[fd] = lin.tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!lin.ret && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (write_line(str, line, fd));
}

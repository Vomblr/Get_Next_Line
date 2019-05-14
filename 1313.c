/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1313.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:05:52 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/14 20:05:57 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	write_line(char **str, char **line, int fd, int ret)
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
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	t_line		lin;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((lin.ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[lin.ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		lin.tmp = ft_strjoinfree(str[fd], buff, 1);
		str[fd] = lin.tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (lin.ret < 0)
		return (-1);
	else if (lin.ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (write_line(str, line, fd, lin.ret));
}


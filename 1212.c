/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1212.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:05:52 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/14 18:19:46 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	new_line(char **str, char **line, int fd, int ret)
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
			ft_strdel(&str[fd]);//free(str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);//free(str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	t_line		some;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((some.ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[some.ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		some.tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = some.tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (some.ret < 0)
		return (-1);
	if (some.ret == 0 && (str[fd][0] == '\0' || str[fd] == NULL))
		return (0);
	return (new_line(str, line, fd, some.ret));
}


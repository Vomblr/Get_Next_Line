/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:17:51 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/14 20:09:26 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50
# define MAX_FD 300
#include "libft/libft.h"

typedef struct	s_line
{
	char		*tmp;
	int			ret;
}				t_line;

int				get_next_line(const int fd, char **line);
#endif

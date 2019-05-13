/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:17:51 by mcomet            #+#    #+#             */
/*   Updated: 2019/05/13 18:02:22 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

typedef struct	s_line
{
	char		*content;
	int			size;
}				t_line;

int				get_next_line(const int fd, char **line);
#endif

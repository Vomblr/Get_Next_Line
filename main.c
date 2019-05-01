/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:32:28 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/29 21:33:26 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "libft/libft.h"

int				main(void)
{
	char		*line = NULL;
	int			fd = open("./voina.txt", O_RDONLY);

	get_next_line(fd, &line);
	close(fd);
	sleep(20);
	return (0);
}

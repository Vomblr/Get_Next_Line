/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomet <mcomet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:22:28 by mcomet            #+#    #+#             */
/*   Updated: 2019/04/16 17:19:38 by mcomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_link;

	if (!alst || !*alst)
		return ;
	while (*alst != NULL)
	{
		tmp_link = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = tmp_link;
	}
}

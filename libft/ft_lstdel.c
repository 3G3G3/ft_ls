/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:40:34 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 11:58:10 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*u;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		u = *alst;
		(*alst) = (*alst)->next;
		ft_lstdelone(&u, del);
	}
	free(*alst);
	*alst = NULL;
	return ;
}

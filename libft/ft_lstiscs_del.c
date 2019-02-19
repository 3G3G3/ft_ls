/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiscs_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:31:20 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 15:07:44 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiscs_del(t_list **lst, size_t content_size,
												void (*fdel)(void *, size_t))
{
	t_list		*tmp1;
	t_list		*tmp2;

	if (!lst || !*lst)
		return ;
	tmp1 = *lst;
	tmp2 = *lst;
	while (tmp2 && ft_lstiscs(tmp2, content_size) != 1)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	if (!tmp2)
		return ;
	tmp1->next = tmp2->next;
	ft_lstdelone(&tmp2, fdel);
}

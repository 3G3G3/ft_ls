/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:42:12 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/08 13:41:06 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*t;
	t_list		*res;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	if (!res)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		t = f(lst);
		if (!t)
			return (NULL);
		ft_lstadd_fifo(&res, t);
		lst = lst->next;
	}
	return (res);
}

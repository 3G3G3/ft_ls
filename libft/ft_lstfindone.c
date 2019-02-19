/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:41:14 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 11:45:16 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfindone(t_list *lst, int n, int (*fone)(t_list *, size_t))
{
	if (!lst)
		return (NULL);
	while (fone(lst, n) == 0)
		lst = lst->next;
	if (fone(lst, (size_t)n) == 1)
		return (lst);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiscs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:28:26 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 11:29:04 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstiscs(t_list *lst, size_t content_size)
{
	if (!lst)
		return (0);
	if (lst->content_size == content_size)
		return (1);
	return (0);
}

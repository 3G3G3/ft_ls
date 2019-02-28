/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:03:15 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 11:13:20 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddi(t_list **alst, t_list *new)
{
	t_list	*t;

	if (!alst || !(*alst) || !new)
		return ;
	t = (*alst)->next;
	(*alst)->next = new;
	new->next = t;
}

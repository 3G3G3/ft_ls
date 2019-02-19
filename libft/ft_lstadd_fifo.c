/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_fifo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:40:04 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 14:26:58 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_fifo(t_list **alst, t_list *new)
{
	t_list		*t;

	if (!alst || !new)
		return ;
	if (!alst || !(*alst))
		*alst = new;
	else
	{
		t = *alst;
		while (t->next)
			t = t->next;
		t->next = new;
	}
}

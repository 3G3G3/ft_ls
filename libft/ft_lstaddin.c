/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:03:46 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 11:13:28 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddin(t_list *alst1, t_list *alst2, size_t n)
{
	size_t	i;
	t_list	*t;

	if (!alst1 || !alst2)
		return ;
	i = 0;
	while (i < n && alst2)
	{
		t = alst2->next;
		ft_lstaddi(alst1, alst2);
		alst1 = alst1->next;
		alst2 = t;
		i++;
	}
}

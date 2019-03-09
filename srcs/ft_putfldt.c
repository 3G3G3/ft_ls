/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfldt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:03:26 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/09 15:03:27 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putfldt(t_filedata *fldt)
{
	ft_putstr(fldt->input_name);
	ft_putstr(" : ");
	ft_putstr(fldt->path);
	ft_putstr(" : ");
	ft_putstr(fldt->dir);
	ft_putstr(" : ");
	ft_putstr(fldt->name);
	ft_putstr(" : ");
	ft_putstr(fldt->rights);
	ft_putstr(" : ");
	ft_putnbr(fldt->abs_time);
	ft_putendl(";");
}

void		ft_putfldtlst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putfldt(lst->content);
		lst = lst->next;
	}
}

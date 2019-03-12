/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfldt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:03:26 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/12 19:36:30 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putdate(time_t tm)
{
	int		i;
	char  *date;

	i = 4;
	date = ctime(&tm);
	if (date == NULL)
		return ;
	while(i <= 15)
	{
		ft_putchar(date[i]);
		i++;
	}
}

void		ft_putfldt(t_filedata *fldt, char *opts)
{
	if (opts[0] == 'l')
	{
		ft_putstr(fldt->rights);
		ft_putstr(" ");
		ft_putlong(fldt->nlinks);
		ft_putstr(" ");
		ft_putstr(fldt->uid);
		ft_putstr(" ");
		ft_putstr(fldt->gid);
		ft_putstr(" ");
		ft_putllong(fldt->size);
		ft_putstr(" ");
		ft_putdate(fldt->abs_time);
		ft_putstr(" ");
		//	ft_putstr(" : ");
		//	ft_putnbr(fldt->abs_time);
	}
	ft_putendl(fldt->name);
}

void		ft_putfldtlst(t_list *lst, char *opts)
{
	while (lst != NULL)
	{
		ft_putfldt(lst->content, opts);
		lst = lst->next;
	}
}

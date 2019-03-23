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

void	ft_putddyyyy(char *date)
{
	int		i;

	i = 0;
	while (i <= 10)
	{
		if (i >= 8 && i <= 10)
			ft_putchar(date[i]);
		i++;
	}
	i = 4;
	while (i <= 23)
	{
		if ((i >= 4 && i <= 7) || (i >= 19 && i <= 23))
			ft_putchar(date[i]);
		i++;
	}
}

void	ft_putddmmhh(char *date)
{
	int		i;

	i = 0;
	while (i <= 10)
	{
		if (i >= 8 && i <= 10)
			ft_putchar(date[i]);
		i++;
	}
	i = 4;
		while(i <= 15)
		{
			if (i <= 7 || i >= 11)
				ft_putchar(date[i]);
			i++;
		}
}

void	ft_putdate(time_t tm)
{
	char		*date;
	time_t		t;

	date = ctime(&tm);
	t = time(0);
	if (date == NULL || t == -1)
	{
		perror("error asking for actual time in time()");
		return ;
	}
	if (t - tm < 15552000)
		ft_putddmmhh(date);
	else
		ft_putddyyyy(date);
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
	ft_putstr(fldt->name);
	if ((fldt->rights)[0] == 'l' && (opts)[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(fldt->pfile);
	}
	ft_putchar('\n');
}

void		ft_putfldtlst(t_list *lst, char *opts)
{
	while (lst != NULL)
	{
		ft_putfldt(lst->content, opts);
		lst = lst->next;
	}
}

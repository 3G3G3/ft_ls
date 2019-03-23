/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsizes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:48:25 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/23 18:10:40 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len		*ft_initlens(t_len *l)
{
	l = (t_len *)ft_memalloc(sizeof(t_len));
	if (l == NULL)
		return (NULL);
	l->lnlinks = 0;
	l->luid = 0;
	l->lgid = 0;
	l->lsize = 0;
	l->lmajor = 0;
	l->lminor = 0;
	l->nblocks = 0;
	return (l);
}

void		ft_cmplens(t_len *l, t_filedata *fldt)
{
	if (l->lnlinks <= ft_uintlen(fldt->nlinks))
		l->lnlinks = ft_uintlen(fldt->nlinks);
	if (l->luid <= ft_strlen(fldt->uid))
		l->luid = ft_strlen(fldt->uid);
	if (l->lgid <= ft_strlen(fldt->gid))
		l->lgid = ft_strlen(fldt->gid);
	if ((fldt->rights)[0] != 'c' && (fldt->rights)[0] != 'b')
	{
		if (l->lsize <= ft_llen(fldt->size))
			l->lsize = ft_llen(fldt->size);
	}
	else
	{
		if (l->lmajor < ft_uintlen(fldt->spmaj))
			l->lmajor = ft_uintlen(fldt->spmaj);
		if (l->lminor < ft_uintlen(fldt->spmin))
			l->lminor = ft_uintlen(fldt->spmin);
	}
	l->nblocks = l->nblocks + fldt->nblocks;
}

t_len		*ft_getsizes(t_list *lst)
{
	t_len		*res;

	res = NULL;
	res = ft_initlens(res);
	if (res == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_cmplens(res, (t_filedata *)(lst->content));
		lst = lst->next;
	}
	return (res);
}

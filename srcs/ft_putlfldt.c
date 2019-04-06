/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfldt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:03:26 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 18:49:36 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ft_maxsplen(t_len *sizes)
{
	if (sizes->lmajor != 0 && sizes->lminor != 0 &&
			sizes->lmajor + sizes->lminor + 2 > sizes->lsize)
		return (sizes->lmajor + sizes->lminor + 2);
	return (sizes->lsize);
}

size_t		ft_getbufsize(t_len *sizes)
{
	size_t		res;

	res = 31 + sizes->lnlinks + sizes->luid + sizes->lgid;
	return (res + ft_maxsplen(sizes));
}

void		ft_fillbuf(t_filedata *fldt, t_len *sizes, char *buf)
{
	size_t		i;

	i = 0;
	i = ft_strlen(fldt->rights);
	ft_memcpy(buf, fldt->rights, i);
	i = i + 1;
	ft_getuint(fldt->nlinks,
			buf + i + sizes->lnlinks - ft_uintlen(fldt->nlinks));
	i = i + 1 + sizes->lnlinks;
	ft_memcpy(buf + i, fldt->uid, ft_strlen(fldt->uid));
	i = i + 2 + sizes->luid;
	ft_memcpy(buf + i, fldt->gid, ft_strlen(fldt->gid));
	i = i + 2 + sizes->lgid;
	if ((fldt->rights)[0] != 'c' && (fldt->rights)[0] != 'b')
		ft_getl(fldt->size, buf + i + ft_maxsplen(sizes) - ft_llen(fldt->size));
	else
	{
		ft_getuint(fldt->spmaj,
				buf + i + sizes->lmajor - ft_uintlen(fldt->spmaj));
		buf[i + sizes->lmajor] = ',';
		ft_getuint(fldt->spmin,
				buf + i + ft_maxsplen(sizes) - ft_uintlen(fldt->spmin));
	}
	i = i + 1 + ft_maxsplen(sizes);
	ft_getdate(fldt->abs_time, buf + i);
}

void		ft_putfldt(t_filedata *fldt, char *opts, t_len *sizes)
{
	char	*buf;

	if (opts[5] == 'i')
	{
		write(1, "                   ", sizes->lino - ft_uintlen(fldt->ino));
		ft_putuint(fldt->ino);
		ft_putchar(' ');
	}
	if (opts[0] == 'l')
	{
		buf = ft_strnew(ft_getbufsize(sizes));
		if (buf == NULL)
			return ;
		ft_memset(buf, ' ', ft_getbufsize(sizes));
		ft_fillbuf(fldt, sizes, buf);
		write(1, buf, ft_getbufsize(sizes));
		free(buf);
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
	t_len		*sizes;

	if (opts[0] == 'l' || opts[5] == 'i')
	{
		sizes = ft_getsizes(lst, opts);
		if (sizes == NULL)
			return ;
		if (opts[0] == 'l')
		{
			ft_putstr("total ");
			ft_putllong(sizes->nblocks);
			ft_putchar('\n');
		}
	}
	else
		sizes = NULL;
	while (lst != NULL)
	{
		ft_putfldt(lst->content, opts, sizes);
		lst = lst->next;
	}
	if (sizes != NULL)
		free(sizes);
}

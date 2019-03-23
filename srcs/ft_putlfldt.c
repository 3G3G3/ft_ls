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

size_t		ft_uintlen(unsigned int n)
{
	size_t	res;

	res = 1;
	while ((n = n / 10) != 0)
		res++;
	return (res);
}

void		ft_getuint(unsigned int n, char *buf)
{
	size_t		i;

	i = ft_uintlen(n) - 1;
	if (n == 0)
		buf[0] = '0';
	while (n > 0)
	{
		buf[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

size_t		ft_llen(long n)
{
	size_t	res;

	res = 1;
	while ((n = n / 10) != 0)
		res++;
	return (res);
}

void		ft_getl(long n, char *buf)
{
	size_t		i;

	i = ft_uintlen(n) - 1;
	if (n == 0)
		buf[0] = '0';
	while (n > 0)
	{
		buf[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
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

void	ft_putddyyyy(char *date, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 10)
	{
		if (i >= 8 && i <= 10)
		{
			buf[j] = date[i];
			j++;
		}
		i++;
	}
	i = 4;
	while (i <= 23)
	{
		if ((i >= 4 && i <= 7) || (i >= 19 && i <= 23))
		{
			buf[j] = date[i];
			j++;
		}
		i++;
	}
}

void	ft_putddmmhh(char *date, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 10)
	{
		if (i >= 8 && i <= 10)
		{
			buf[j] = date[i];
			j++;
		}
		i++;
	}
	i = 4;
		while(i <= 15)
		{
			if (i <= 7 || i >= 11)
			{
				buf[j] = date[i];
				j++;
			}
			i++;
		}
}

void	ft_getdate(time_t tm, char *buf)
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
		ft_putddmmhh(date, buf);
	else
		ft_putddyyyy(date, buf);
}

size_t		ft_maxspsize(t_len *sizes)
{
	if (sizes->lmajor + sizes->lminor + 2 > sizes->lsize)
		return (sizes->lmajor + sizes->lminor + 2);
	return (sizes->lsize);
}

size_t		ft_getbufsize(t_len *sizes)
{
	size_t		res;

	res = 30 + sizes->lnlinks + sizes->luid + sizes->lgid;
	return (res + ft_maxspsize(sizes));
}

void		ft_fillbuf(t_filedata *fldt, t_len *sizes, char *buf)
{
	size_t		i;

	i = 0;
	i = ft_strlen(fldt->rights);
	ft_memcpy(buf, fldt->rights, i);
	i = i + 1;
	ft_getuint(fldt->nlinks, buf + i + sizes->lnlinks - ft_uintlen(fldt->nlinks));
	i = i + 1 + sizes->lnlinks;
	ft_memcpy(buf + i, fldt->uid, ft_strlen(fldt->uid));
	i = i + 2 + sizes->luid;
	ft_memcpy(buf + i, fldt->gid, ft_strlen(fldt->gid));
	i = i + 1 + sizes->lgid;
	if ((fldt->rights)[0] != 'c' && (fldt->rights)[0] != 'b')
		ft_getl(fldt->size, buf + i + ft_maxspsize(sizes) - ft_llen(fldt->size));
	else
	{
		ft_getuint(fldt->spmaj, buf + i + sizes->lmajor - ft_uintlen(fldt->spmaj));
		buf[i + sizes->lmajor] = ',';
		ft_getuint(fldt->spmin, buf + i + ft_maxspsize(sizes) - ft_uintlen(fldt->spmin));
	}
	i = i + 1 + ft_maxspsize(sizes);
	ft_getdate(fldt->abs_time, buf + i);
}

void		ft_putfldt(t_filedata *fldt, char *opts, t_len *sizes)
{
	char	*buf;

	if (opts[0] == 'l')
	{
		buf = ft_strnew(ft_getbufsize(sizes));
		ft_memset(buf, ' ', ft_getbufsize(sizes));
		if (buf == NULL)
			return ;
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

	if (opts[0] == 'l')
	{
		sizes = ft_getsizes(lst);
		if (sizes == NULL)
			return ;
		ft_putstr("total ");
		ft_putllong(sizes->nblocks);
		ft_putchar('\n');
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

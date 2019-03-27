/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:13:46 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/27 10:52:11 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_fldt_listnew(struct dirent *dir, char *fdir, char *opts)
{
	t_filedata		*fldt;
	t_list			*res;

	fldt = ft_getstat0(dir, fdir, opts);
	if (fldt == NULL)
		return (NULL);
	fldt->dir = ft_strdup(fdir);
	if (fldt->dir == NULL)
	{
		ft_freefldt(&fldt);
		return (NULL);
	}
	res = ft_lstnew(fldt, sizeof(t_filedata));
	free(fldt);
	if (res == NULL)
		return (NULL);
	return (res);
}

void			ft_readdir(t_filedata *fldt, char *opts)
{
	DIR			*fd;
	t_list		*lvl0;
	char		*path;

	fd = ft_opendir(fldt->path);
	if (fd == NULL)
		return ;
	path = ft_normpath(fldt->path);
	if (path == NULL)
		return ;
	fldt->path = path;
	lvl0 = ft_readlvl0(fd, path, opts);
	if (lvl0 == NULL)
		return ;
	closedir(fd);
	ft_putfldtlst(lvl0, opts);
	if (opts[1] == 'R')
		ft_readlvln(lvl0, opts);
	ft_freelst(&lvl0);
}

void			ft_readinput(t_list *dir_lst, char *opts, char ftype)
{
	int			p;

	p = 1;
	if (dir_lst->next == NULL)
		p = -1;
	while (dir_lst != NULL)
	{
		if (((((t_filedata *)(dir_lst->content))->rights)[0] == ftype &&
				ftype != 'l') ||
			((((t_filedata *)(dir_lst->content))->rights)[0] == 'l' &&
				ftype == 'd'))
		{
			if (p == 1)
			{
				ft_putstr(((t_filedata *)(dir_lst->content))->input_name);
				ft_putendl(":");
			}
			if (ftype == 'd' || ftype == 'l')
				ft_readdir((t_filedata *)(dir_lst->content), opts);
			if (dir_lst->next != NULL)
				ft_putchar('\n');
		}
		dir_lst = dir_lst->next;
	}
}

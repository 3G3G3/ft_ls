/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:13:46 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 20:23:57 by grgauthi         ###   ########.fr       */
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
	closedir(fd);
	if (lvl0 == NULL)
		return ;
	ft_putfldtlst(lvl0, opts);
	if (opts[1] == 'R')
		ft_readlvln(lvl0, opts);
	ft_freelst(&lvl0);
}

void			ft_del_readndir(char *path, t_stat *stats, t_len *size)
{
	if (path != NULL)
		free(path);
	if (stats != NULL)
		free(stats);
	if (size != NULL)
		free(size);
}

void			ft_readndir(t_filedata *fldt, char *opts)
{
	char		*path;
	t_stat		*stats;
	t_len		*size;
	t_list		*tmp;

	path = ft_strjoin(fldt->dir, fldt->name);
	stats = (t_stat *)ft_memalloc((sizeof(t_stat)));
	size = NULL;
	if (path == NULL || stats == NULL)
		return (ft_del_readndir(path, stats, size));
	if (lstat(path, stats) == -1)
		return (ft_del_readndir(path, stats, size));
	free(fldt->rights);
	if ((fldt = ft_convertstats(fldt, stats, opts)) != NULL)
	{
		if ((tmp = ft_lstnew(fldt, sizeof(t_filedata))) != NULL)
		{
			if ((size = ft_getsizes(tmp, opts)) == NULL)
				return (ft_del_readndir(path, stats, size));
			ft_putfldt(fldt, opts, size);
			free(tmp->content);
			free(tmp);
		}
	}
	ft_del_readndir(path, stats, size);
}

void			ft_readinput(t_list *dir_lst, char *opts, char ftype)
{
	while (dir_lst != NULL)
	{
		if ((((t_filedata *)(dir_lst->content))->rights)[0] == ftype)
		{
			if (ftype == 'd')
			{
				ft_putstr(((t_filedata *)(dir_lst->content))->input_name);
				ft_putendl(":");
				ft_readdir((t_filedata *)(dir_lst->content), opts);
			}
			else
				ft_readndir((t_filedata *)(dir_lst->content), opts);
			if (dir_lst->next != NULL)
				ft_putchar('\n');
		}
		dir_lst = dir_lst->next;
	}
}

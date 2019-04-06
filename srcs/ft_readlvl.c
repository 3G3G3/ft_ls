/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:09:46 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/23 17:41:17 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_readlvl0(DIR *fd_dir, char *fdir, char *opts)
{
	struct dirent		*dir;
	t_list				*res;
	t_list				*tmp_res;

	errno = 0;
	dir = readdir(fd_dir);
	while (dir != NULL && !(opts[2] == 'a' || (dir->d_name)[0] != '.'))
		dir = readdir(fd_dir);
	if (dir == NULL && errno != 0)
		g_output = 2;
	if (dir == NULL)
		return (NULL);
	res = ft_fldt_listnew(dir, fdir, opts);
	while ((dir = readdir(fd_dir)) != NULL && res != NULL)
	{
		if (opts[2] == 'a' || (dir->d_name)[0] != '.')
		{
			if ((tmp_res = ft_fldt_listnew(dir, fdir, opts)) == NULL)
				ft_freelst(&res);
			if (res)
				ft_lstsortedadd(&res, tmp_res, opts);
		}
	}
	return (res);
}

int				ft_toexplore(t_list *files, char *opts)
{
	if (((ft_strcmp(((t_filedata *)(files->content))->name, ".") == 0 ||
		ft_strcmp(((t_filedata *)(files->content))->name, "..") == 0)) ||
		(opts[2] == '-' && (((t_filedata *)(files->content))->name)[0] == '.'))
		return (-1);
	return (1);
}

void			ft_putlvln(char *path, t_list *lvln, char *opts)
{
	if (lvln == NULL && errno != 0)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": error reading lvln");
		return ;
	}
	if (lvln == NULL)
		return ;
	ft_putfldtlst(lvln, opts);
	ft_readlvln(lvln, opts);
}

void			ft_readlvln(t_list *files, char *opts)
{
	DIR			*fd_dir;
	t_list		*lvln;
	char		*path;

	while (files != NULL)
	{
		if (ft_toexplore(files, opts) == 1 &&
				(((t_filedata *)(files->content))->rights)[0] == 'd')
		{
			ft_putstr("\n");
			path = ft_buildpath((t_filedata *)(files->content));
			ft_putstr(path);
			ft_putendl(":");
			if (path == NULL)
				return ;
			if ((fd_dir = ft_opendir(path)) != NULL)
			{
				lvln = ft_readlvl0(fd_dir, path, opts);
				closedir(fd_dir);
				ft_putlvln(path, lvln, opts);
				if (lvln != NULL)
					ft_freelst(&lvln);
			}
			free(path);
		}
		files = files->next;
	}
}

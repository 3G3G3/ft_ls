/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:09:46 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 19:52:40 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_toexplore(t_list *files, char *opts)
{
	if (((ft_strcmp(((t_filedata *)(files->content))->name, ".") == 0
			|| ft_strcmp(((t_filedata *)(files->content))->name, "..") == 0))
		|| (opts[2] == '-'
			&& (((t_filedata *)(files->content))->name)[0] == '.'))
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
	ft_browselvln(lvln, opts);
}

char			*ft_putheadline(t_filedata *fldt)
{
	char		*path;

	ft_putstr("\n");
	path = ft_buildpath(fldt);
	if (path == NULL)
		return (NULL);
	path = ft_strjoinfree(&path, "/");
	if (path == NULL)
		return (NULL);
	ft_putstr(path);
	ft_putendl(":");
	return (path);
}

void			ft_browselvln_body(t_list *files, DIR *fd_dir, char *path,
		char *opts)
{
	t_list		*lvln;

	((t_filedata *)(files->content))->nblocks = 0;
	lvln = ft_readlvl0(fd_dir, path, opts,
			&(((t_filedata *)(files->content))->nblocks));
	closedir(fd_dir);
	if (opts[0] == 'l' && ft_lstlen(lvln) > 0)
		ft_puttot(((t_filedata *)(files->content))->nblocks);
	ft_putlvln(path, lvln, opts);
	if (lvln != NULL)
		ft_freelst(&lvln);
}

void			ft_browselvln(t_list *files, char *opts)
{
	DIR			*fd_dir;
	char		*path;

	while (files != NULL)
	{
		if (ft_toexplore(files, opts) == 1 &&
				(((t_filedata *)(files->content))->rights)[0] == 'd')
		{
			path = ft_putheadline((t_filedata *)(files->content));
			if (path == NULL)
				return ;
			if ((fd_dir = ft_opendir(path)) != NULL)
				ft_browselvln_body(files, fd_dir, path, opts);
			free(path);
		}
		files = files->next;
	}
}

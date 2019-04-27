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

t_list		*ft_exploredirinit(t_filedata *fldt, char *opts, blksize_t *nblocks)
{
	DIR			*fd;
	t_list		*lvl0;
	char		*path;

	fd = ft_opendir(fldt->path);
	if (fd == NULL)
		return (NULL);
	path = ft_normpath(fldt->path);
	if (path == NULL)
		return (NULL);
	fldt->path = path;
	*nblocks = 0;
	lvl0 = ft_readlvl0(fd, path, opts, nblocks);
	closedir(fd);
	return (lvl0);
}

void			ft_exploredir(t_filedata *fldt, char *opts, size_t iput)
{
	t_list		*lvl0;
	blksize_t	nblocks;

	lvl0 = ft_exploredirinit(fldt, opts, &nblocks);
	if (lvl0 == NULL)
		return ;
	if (iput == 2)
		ft_putchar('\n');
	if (iput > 0)
	{
		ft_putstr(fldt->path);
		ft_putendl(":");
	}
	if (opts[0] == 'l' && (fldt->rights)[0] == 'd')
		ft_puttot(nblocks);
	ft_putfldtlst(lvl0, opts);
	if (opts[1] == 'R')
		ft_browselvln(lvl0, opts);
	ft_freelst(&lvl0);
}

size_t			ft_infoput(size_t iput, size_t ndir, size_t i)
{
	if (iput > 0 || i > 0)
		return (2);
	if (ndir > 1)
		return (1);
	return (0);
}

void			ft_browseinput(t_list *dir_lst, char *opts, size_t iput)
{
	size_t		i;
	size_t		ndir;

	ndir = ft_lstlen(dir_lst) - 1;
	i = 0;
	while (dir_lst != NULL)
	{
		if (ft_strcmp(((t_filedata *)(dir_lst->content))->rights, "0") != '\0')
		{
			ft_exploredir((t_filedata *)(dir_lst->content), opts,
				ft_infoput(iput - 2, ndir, i));
			i++;
		}
		dir_lst = dir_lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:44:37 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 20:37:57 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_readlvl0_parse(struct dirent *dir)
{
	if (dir == NULL && errno != 0)
		g_output = 2;
}

t_list				*ft_rtnoutput(void)
{
	g_output = (g_output == 2) ? 2 : 1;
	return (NULL);
}

void				ft_readlvl0_body(char *dpath, char *opts, t_list **res,
						blksize_t *nblocks)
{
	t_list			*tmp;

	if ((tmp = ft_newfile(dpath, opts)) == NULL)
		ft_freelst(res);
	if (res)
	{
		*nblocks = *nblocks + ((t_filedata *)(tmp->content))->nblocks;
		ft_lstsortedadd(res, tmp, opts);
	}
}

t_list				*ft_readlvl0(DIR *fd_dir, char *path, char *opts,
						blksize_t *nblocks)
{
	struct dirent	*dir;
	t_list			*res;
	char			*dpath;

	errno = 0;
	while ((dir = readdir(fd_dir)) != NULL
			&& !(opts[2] == 'a' || (dir->d_name)[0] != '.'))
		;
	ft_readlvl0_parse(dir);
	if (dir == NULL)
		return (ft_rtnoutput());
	if ((dpath = ft_strjoin(path, dir->d_name)) == NULL)
		return (NULL);
	res = ft_newfile(dpath, opts);
	*nblocks = ((t_filedata *)(res->content))->nblocks;
	while ((dir = readdir(fd_dir)) != NULL && res != NULL)
	{
		if (opts[2] == 'a' || (dir->d_name)[0] != '.')
		{
			if ((dpath = ft_strjoin(path, dir->d_name)) == NULL)
				return (NULL);
			ft_readlvl0_body(dpath, opts, &res, nblocks);
		}
	}
	return (res);
}

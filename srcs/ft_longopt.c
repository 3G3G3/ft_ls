/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:31:39 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/27 11:01:12 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata		*ft_getlongopt(t_filedata *fldt, t_stat *stats, char *path)
{
	struct passwd	*uid;
	struct group	*gid;

	fldt->nlinks = stats->st_nlink;
	fldt->size = stats->st_size;
	uid = getpwuid(stats->st_uid);
	fldt->uid = ft_strdup(uid->pw_name);
	if (fldt->uid == NULL || (gid = getgrgid(stats->st_gid)) == NULL ||
			(fldt->gid = ft_strdup(gid->gr_name)) == NULL)
	{
		ft_freefldt(&fldt);
		return (NULL);
	}
	if ((fldt->rights)[0] == 'l')
	{
		fldt->pfile = ft_strnew(63);
		if (fldt->pfile == NULL || readlink(path, fldt->pfile, 63) == -1)
		{
			ft_freefldt(&fldt);
			if (readlink(path, fldt->pfile, 63) == -1)
				perror("Error reading link by readlink");
			return (NULL);
		}
	}
	return (fldt);
}

t_filedata		*ft_getinoopt(t_filedata *fldt, t_stat *stats)
{
	fldt->ino = stats->st_ino;
	return (fldt);
}

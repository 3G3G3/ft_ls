/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:51:29 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/27 12:05:13 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_getfiletype(t_stat *stats)
{
	char	res;

	res = '-';
	if (S_ISDIR(stats->st_mode))
		res = 'd';
	if (S_ISCHR(stats->st_mode))
		res = 'c';
	if (S_ISBLK(stats->st_mode))
		res = 'b';
	if (S_ISFIFO(stats->st_mode))
		res = 'p';
	if (S_ISLNK(stats->st_mode))
		res = 'l';
	if (S_ISSOCK(stats->st_mode))
		res = 's';
	return (res);
}

void		ft_convertrights(t_stat *stats, char *rights)
{
	rights[0] = ft_getfiletype(stats);
	rights[1] = ((stats->st_mode & S_IRUSR) ? 'r' : '-');
	rights[2] = ((stats->st_mode & S_IWUSR) ? 'w' : '-');
	rights[3] = ((stats->st_mode & S_IXUSR) ? 'x' : '-');
	if ((stats->st_mode & S_IXUSR) && (stats->st_mode & S_ISUID))
		rights[3] = 's';
	if (!(stats->st_mode & S_IXUSR) && (stats->st_mode & S_ISUID))
		rights[3] = 'S';
	rights[4] = ((stats->st_mode & S_IRGRP) ? 'r' : '-');
	rights[5] = ((stats->st_mode & S_IWGRP) ? 'w' : '-');
	rights[6] = ((stats->st_mode & S_IXGRP) ? 'x' : '-');
	if ((stats->st_mode & S_IXGRP) && (stats->st_mode & S_ISGID))
		rights[6] = 's';
	if (!(stats->st_mode & S_IXGRP) && (stats->st_mode & S_ISGID))
		rights[6] = 'S';
	rights[7] = ((stats->st_mode & S_IROTH) ? 'r' : '-');
	rights[8] = ((stats->st_mode & S_IWOTH) ? 'w' : '-');
	rights[9] = ((stats->st_mode & S_IXOTH) ? 'x' : '-');
	if ((stats->st_mode & S_IXOTH) && (stats->st_mode & S_ISVTX))
		rights[9] = 't';
	if (!(stats->st_mode & S_IXOTH) && (stats->st_mode & S_ISVTX))
		rights[9] = 'T';
	rights[10] = ' ';
}

t_filedata	*ft_convertstat(t_filedata *fldt, struct dirent *dir, t_stat *stats,
		char *opts)
{
	fldt->name = ft_strdup(dir->d_name);
	fldt->rights = ft_strnew(11);
	if (fldt->name == NULL || fldt->rights == NULL)
	{
		ft_freefldt(&fldt);
		return (NULL);
	}
	fldt->abs_time = stats->st_mtime;
	ft_convertrights(stats, fldt->rights);
	if (opts[0] == 'l' && ft_getlongopt(fldt, stats, fldt->path) == NULL)
		return (NULL);
	if (opts[5] == 'i')
		fldt->ino = stats->st_ino;
	fldt->nblocks = stats->st_blocks;
	if ((fldt->rights)[0] == 'b' || (fldt->rights)[0] == 'c')
	{
		fldt->spmaj = (stats->st_rdev) >> 24;
		fldt->spmin = (stats->st_rdev) & 0xFFFFFF;
	}
	return (fldt);
}

void		ft_freestats(t_filedata *fldt, t_stat *stats, char *bpath)
{
	if (fldt != NULL)
		free(fldt);
	if (stats != NULL)
		free(stats);
	if (bpath != NULL)
		free(bpath);
}

t_filedata	*ft_getstat0(struct dirent *dir, char *fdir, char *opts)
{
	t_filedata	*fldt;
	t_stat		*stats;
	char		*bpath;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	bpath = ft_strjoin(fdir, dir->d_name);
	if (fldt == NULL || stats == NULL || bpath == NULL)
	{
		ft_freestats(fldt, stats, bpath);
		return (NULL);
	}
	if (lstat(bpath, stats) == -1)
	{
		ft_freestats(fldt, stats, bpath);
		return (NULL);
	}
	fldt->path = bpath;
	fldt = ft_convertstat(fldt, dir, stats, opts);
	ft_freestats(NULL, stats, NULL);
	return (fldt);
}

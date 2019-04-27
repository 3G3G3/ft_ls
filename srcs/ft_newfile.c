#include "ft_ls.h"

t_list			*ft_createfile(t_filedata *fldt)
{
	t_list		*res;

	if ((res = ft_lstnew(fldt, sizeof(t_filedata))) == NULL)
	{
		ft_freefldt(&fldt);
		return (NULL);
	}
	free(fldt);
	return (res);
}

int				ft_parsepath(char *path, t_filedata *fldt)
{
	fldt->path = path;
	fldt->dir = ft_strdup(path);
	fldt->name = ft_strdup(path + ft_getlastslash(path) + 1);
	if (fldt->dir == NULL || fldt->name == NULL)
	{
		ft_freeobjs(fldt->dir, fldt->name, NULL, NULL);
		return (-1);
	}
	ft_strclr(fldt->dir + ft_getlastslash(path));
	return (1);
}

t_filedata		*ft_getstats(char *path, char *opts)
{
	t_filedata	*fldt;
	t_stat		*stats;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (fldt == NULL || stats == NULL || ft_parsepath(path, fldt) == -1)
	{
		ft_freeobjs(fldt, stats, NULL, NULL);
		return (NULL);
	}
	if (lstat(path, stats) == -1)
	{
		g_output = 2;
		ft_freeobjs(stats, fldt->dir, fldt->name, fldt);
		return (NULL);
	}
	fldt = ft_convertstats(fldt, stats, opts);
	free(stats);
	return (fldt);
}

t_list			*ft_newfile(char *path, char *opts)
{
	t_filedata	*fldt;
	t_list		*res;

	if (path == NULL)
		path = ft_strdup(".");
	if (path == NULL)
		return (NULL);
	fldt = ft_getstats(path, opts);
	if (fldt == NULL)
		return (NULL);
	res = ft_createfile(fldt);
	if (res == NULL)
	{
		ft_freefldt(&fldt);
		return (NULL);
	}
	return (res);
}

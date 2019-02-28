#include "ft_ls.h"

void		ft_convertrights(t_stat *stats, char *rights)
{
	rights[0] = ( (S_ISDIR(stats->st_mode)) ? 'd': '-');
	rights[1] = ( (stats->st_mode & S_IRUSR) ? 'r' : '-');
	rights[2] = ( (stats->st_mode & S_IWUSR) ? 'w' : '-');
	rights[3] = ( (stats->st_mode & S_IXUSR) ? 'x' : '-');
	rights[4] = ( (stats->st_mode & S_IRGRP) ? 'r' : '-');
	rights[5] = ( (stats->st_mode & S_IWGRP) ? 'w' : '-');
	rights[6] = ( (stats->st_mode & S_IXGRP) ? 'x' : '-');
	rights[7] = ( (stats->st_mode & S_IROTH) ? 'r' : '-');
	rights[8] = ( (stats->st_mode & S_IWOTH) ? 'w' : '-');
	rights[9] = ( (stats->st_mode & S_IXOTH) ? 'x' : '-');
	rights[10] = ' ';
}

t_filedata	*ft_convertstat(t_filedata *fldt, struct dirent *dir, t_stat *stats)
{
	fldt->name = ft_strdup(dir->d_name);
	if (fldt->name == NULL)
	{
		ft_putendl("a");
		free(fldt);
		return (NULL);
	}
	fldt->rights = ft_strnew(10);
	if (fldt->rights == NULL)
	{
		ft_putendl("b");
		free(fldt->name);
		free(fldt);
		return (NULL);
	}
	fldt->abs_time = stats->st_mtime;
	ft_convertrights(stats, fldt->rights);
	return (fldt);
}

t_filedata	*ft_getstat(struct dirent *dir, char *path)
{
	t_filedata	*fldt;
	t_stat		*stats;
	char		*bpath;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (stats == NULL)
	{
		free(fldt);
		return (NULL);
	}
	bpath = ft_strjoin(path, dir->d_name);
	if (bpath == NULL)
	{
		free(fldt);
		free(stats);
		return (NULL);
	}
	if (stat(bpath, stats) == -1)
	{
		ft_putendl("essaye encore");
		free(stats);
		free(fldt);
		return (NULL);
	}
	fldt = ft_convertstat(fldt, dir, stats);
	free(stats);
	free(bpath);
	return (fldt);
}

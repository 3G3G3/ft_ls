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

t_filedata	*ft_getstat(char *path, struct dirent *dir)
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

t_list			*ft_fldt_listnew(struct dirent *dir, char *path)
{
	t_filedata		*fldt;
	t_list			*res;

	fldt = ft_getstat(path, dir);
	if (fldt == NULL)
		return (NULL);
	fldt->path = path;
	//	ft_putfldt(fldt);
	res = ft_lstnew(fldt, sizeof(t_filedata));
	free(fldt);
//	fldt = (t_filedata *)res->content;
//	res->content = fldt;
	if (res == NULL)
		return (NULL);
	return (res);
}

t_list			*ft_readlvl0(DIR *fd_dir, char *path)
{
	struct dirent		*dir;
	t_list				*res;
	t_list				*tmp_res;

	dir = readdir(fd_dir);
	if (dir == NULL)
	{
		ft_putendl("there");
		return (NULL);
	}
	res = ft_fldt_listnew(dir, path);
	while ((dir = readdir(fd_dir)) != NULL)
	{
		tmp_res = ft_fldt_listnew(dir, path);
		if (tmp_res == NULL)
		{
			ft_freelst(&res);
			return (NULL);
		}
		ft_lstsortedadd(&res, tmp_res, "");
//		ft_putfldtlst(res);
//		ft_lstadd(&res, tmp_res);
	}
	return (res);
}

char			*ft_buildpath(t_filedata *fldt)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = ft_strjoin(fldt->path, fldt->name);
	if (tmp1 == NULL)
		return (NULL);
	tmp2 = ft_strjoinfree(&tmp1, "/");
	if (tmp2 == NULL)
	{
		free(tmp1);
		return (NULL);
	}
	return (tmp2);
}

int				ft_readlvln(t_list *files)
{
	DIR			*fd_dir;
	t_list		*lvln;
	char		*path;

	/*
	   Trier selon les options demandées
	*/
	while (files != NULL)
	{
		if ((((t_filedata *)(files->content))->name)[ft_strlen(((t_filedata *)(files->content))->name) - 1] == '.')
			ft_putendl(".. or . escaped");
		else if ((((t_filedata *)(files->content))->rights)[0] == 'd')
		{
			path = ft_buildpath((t_filedata *)(files->content));
			if (path == NULL)
				return (0);
			fd_dir = opendir(path);
			if (fd_dir == NULL)
			{
				free(path);
				ft_putendl("ici");
				return (0);
			}
			lvln = ft_readlvl0(fd_dir, path);
			closedir(fd_dir);
			ft_putfldtlst(lvln);
			ft_readlvln(lvln);
			ft_freelst(&lvln);
			free(path);
		}
		files = files->next;
	}
	return (1);
}


int main(int argc, char **argv)
{
	DIR					*fd_dir;
	t_list				*dir_lst;
	char				*path;

	if (argc == 2)
		path = argv[1];
	else
		path = "./";
	fd_dir = opendir(path);
	if (fd_dir == NULL)
	{
		ft_putendl("ici");
		return (0);
	}
	dir_lst = ft_readlvl0(fd_dir, path);
	closedir(fd_dir);
	if (dir_lst == NULL)
		ft_putendl("regarde moi");
	ft_putfldtlst(dir_lst);
//	ft_readlvln(dir_lst);
	if (dir_lst != NULL)
	{
		ft_putendl("la");
		ft_freelst(&dir_lst);
	}
	return (1);
}

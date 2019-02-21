#include "ft_ls.h"

void		ft_freefldt(t_filedata *fldt)
{
		free(fldt->name);
		free(fldt->rights);
}

void		ft_freelst(t_list **elem)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *elem;
	while (tmp1 != NULL)
	{
		ft_freefldt(tmp1->content);
		free(tmp1->content);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = NULL;
		tmp1 = tmp2;
	}
}

int				ft_readlvln(DIR *fd_dir)
{
	(void)fd_dir;
	/*
	   Recuprer toutes les info necessaires (fonction des options demandées)
	   Stockage sous forme de liste

	   Trier selon les options demandées

	   Imprimer l'ensemble des fichiers

	   Imprimer le nom du dossier (NULL dans le cas du niveau 0)
	   Appliquer la fonction de manière récursive sur chacun des repertoires 
	   (fonction de -R)
	   */
	return (1);
}

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
		free(fldt);
		return (NULL);
	}
	fldt->rights = ft_strnew(10);
	if (fldt->rights == NULL)
	{
		free(fldt->name);
		free(fldt);
		return (NULL);
	}
	ft_convertrights(stats, fldt->rights);
	return (fldt);
}

t_filedata	*ft_getstat(struct dirent *dir)
{
	t_filedata	*fldt;
	t_stat		*stats;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (stats == NULL)
	{
		free(fldt);
		return (NULL);
	}
	if (stat(dir->d_name, stats) == -1)
	{
		free(stats);
		free(fldt);
		return (NULL);
	}
	fldt = ft_convertstat(fldt, dir, stats);
	free(stats);
	return (fldt);
}

t_list			*ft_fldt_listnew(struct dirent	*dir)
{
	t_filedata		*fldt;
	t_list			*res;

	fldt = ft_getstat(dir);
	if (fldt == NULL)
		return (NULL);
	res = ft_lstnew(fldt, sizeof(t_filedata));
	free(fldt);
	if (res == NULL)
		return (NULL);
	return (res);
}

t_list			*ft_readlvl0(DIR *fd_dir)
{
	struct dirent		*dir;
	t_list				*res;
	t_list				*tmp_res;

	dir = readdir(fd_dir);
	if (dir == NULL)
		return (NULL);
	res = ft_fldt_listnew(dir);
	while ((dir = readdir(fd_dir)) != NULL)
	{
		tmp_res = ft_fldt_listnew(dir);
		if (tmp_res == NULL)
		{
			ft_freelst(&res);
			return (NULL);
		}
		ft_lstadd(&res, tmp_res);
	}
	return (res);
}

int main()
{
	DIR					*fd_dir;
	t_list				*dir_lst;
	t_list				*lst_read;

	fd_dir = opendir(".");
	if (fd_dir == NULL)
		return (0);
	dir_lst = ft_readlvl0(fd_dir);
	closedir(fd_dir);
	lst_read = dir_lst;
	while (lst_read != NULL)
	{
		ft_putstr(((t_filedata *)(lst_read->content))->name);
		ft_putstr(" : ");
		ft_putstr(((t_filedata *)(lst_read->content))->rights);
		ft_putendl(";");
		lst_read = lst_read->next;
	}
	if (dir_lst != NULL)
		ft_freelst(&dir_lst);
	return (1);
}

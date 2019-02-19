#include "ft_ls.h"


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

t_filedata		*ft_fldt_init(t_filedata *fldt, struct dirent *dir)
{
	fldt->name = ft_strdup(dir->d_name);
	if (fldt->name == NULL)
		return (NULL);
	return (fldt);
}

t_list			*ft_fldt_listnew(struct dirent	*dir)
{
	t_filedata	*fldt;
	t_list		*res;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	fldt = ft_fldt_init(fldt, dir);
	res = ft_lstnew(fldt, sizeof(t_filedata));
	free(fldt);
	if (res == NULL)
		return (NULL);
	return (res);
}

t_list			*ft_readlvl0(DIR *fd_dir)
{
	struct dirent		*dir;
	t_list		*res;
	t_list		*tmp_res;

	dir = readdir(fd_dir);
	if (dir == NULL)
		return (NULL);
	res = ft_fldt_listnew(dir);
	while ((dir = readdir(fd_dir)) != NULL)
	{
		tmp_res = ft_fldt_listnew(dir);
		if (tmp_res == NULL)
		{
		ft_fldtfree(&res);
			return (NULL);
		}
		ft_lstadd(&res, tmp_res);
	}
	return (res);
}

void		ft_fldtfree(t_list **elem)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *elem;
	while (tmp1 != NULL)
	{
		free(((t_filedata *)(tmp1->content))->name);
		free(tmp1->content);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = NULL;
		tmp1 = tmp2;
	}
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
		ft_putendl(((t_filedata *)(lst_read->content))->name);
		lst_read = lst_read->next;
	}
	ft_fldtfree(&dir_lst);
	return (1);
}

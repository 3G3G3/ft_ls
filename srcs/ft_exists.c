#include "ft_ls.h"

time_t		ft_pexists(char *path, char *rights)
{
	time_t		res;
	t_stat		*stats;

	stats = NULL;
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (stats == NULL)
		return (0);
	if (stat(path, stats) == -1)
		return (0);
	res = stats->st_mtime;
	ft_convertrights(stats, rights);
	free(stats);
	return (res);
}

t_list		*ft_exists(t_list *lst)
{
	t_filedata		*fldt;
	t_list			*tmpc;
	t_list			*tmpm;
	t_list			*res;

	tmpc = lst;
	while (lst != NULL && ft_pexists(((t_filedata *)(lst->content))->path,
								((t_filedata *)(lst->content))->rights) == 0)
	{
		lst = lst->next;
		ft_freefldt((t_filedata *)(tmpc->content));
		free(tmpc);
		tmpc = lst;
		ft_putendl("wrong file");
	}
	res = lst;
	tmpm = lst;
	while (lst != NULL)
	{
		tmpc = lst;
		fldt = (t_filedata *)(lst->content);
		fldt->abs_time = ft_pexists(fldt->path, fldt->rights);
		lst = lst->next;
		if (fldt->abs_time == 0)
		{
			tmpm->next = lst;
			ft_freefldt((t_filedata *)(tmpc->content));
			free(tmpc);
			ft_putendl("wrong file");
		}
		else
			tmpm = tmpc;
	}
	return (res);
}

/*
   t_list		*ft_direxists(DIR *fd_dir, t_list *elem)
   {
   struct dirent	*dir;
   t_stat			*stats;

   dir = readdir(fd_dir);
   if (dir == NULL)
   return (NULL);
   if (stat())
   ((t_filedata *)(elem))->abs_time = 
   }


   t_list		*ft_exists(t_list *elem, char *opts)
   {
   DIR				*fd_dir;
   struct dirent	*dir;
   t_stat			*stats;

   opts = (void *)opts;
   stats = NULL;
   fd_dir = ft_opendir(elem);
   if (fd_dir == NULL)
   return (NULL);
   else if (ft_strcmp(((t_filedata *)(elem->content))->name, "") == 0)
   {
   if (!(dir = readdir(fd_dir)) stat(((t_filedata *)(elem->content))->dir, stats) == -1)
   {
   closedir(fd_dir);
   return (NULL);
   }
   ((t_filedata *)(elem->content))->abs_time = stats->st_mtime;
   free(stats);
   closedir(fd_dir);
   return (elem);
   }
   while ((dir = readdir(fd_dir)) != NULL &&
   ft_strcmp(dir->d_name, ((t_filedata *)(elem->content))->name) != 0)
   if (ft_strcmp(dir->d_name, ((t_filedata *)(elem->content))->name) != 0)
   {
   closedir(fd_dir);
   return (NULL);
   }
   if(stat(ft_buildpath(elem->content), stats) == -1)
   return (NULL);
   ((t_filedata *)(elem->content))->abs_time = stats->st_mtime;
   free(stats);
   return (elem);
   }
   */

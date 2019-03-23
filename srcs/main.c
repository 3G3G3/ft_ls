#include "ft_ls.h"

t_list			*ft_fldt_listnew(struct dirent *dir, char *fdir, char *opts)
{
	t_filedata		*fldt;
	t_list			*res;

	fldt = ft_getstat0(dir, fdir, opts);
	if (fldt == NULL)
		return (NULL);
	fldt->dir = ft_strdup(fdir);
	if (fldt->dir == NULL)
		return (NULL);
	//	ft_putfldt(fldt);
	res = ft_lstnew(fldt, sizeof(t_filedata));
	free(fldt);
	//	fldt = (t_filedata *)res->content;
	//	res->content = fldt;
	if (res == NULL)
		return (NULL);
	return (res);
}

t_list			*ft_readlvl0(DIR *fd_dir, char *fdir, char *opts)
{
	struct dirent		*dir;
	t_list				*res;
	t_list				*tmp_res;

	dir = readdir(fd_dir);
	while (dir != NULL &&
			!(opts[2] == 'a' || (dir->d_name)[0] != '.'))
		dir = readdir(fd_dir);
	if (dir == NULL)
	{
		perror("ft_ls: readlvl0");
		return (NULL);
	}
	res = ft_fldt_listnew(dir, fdir, opts);
	while ((dir = readdir(fd_dir)) != NULL)
	{
		if (opts[2] == 'a' || (dir->d_name)[0] != '.')
		{
			tmp_res = ft_fldt_listnew(dir, fdir, opts);
			if (tmp_res == NULL)
			{
				ft_freelst(&res);
				return (NULL);
			}
			ft_lstsortedadd(&res, tmp_res, opts);
		}
	}
	return (res);
}

DIR			*ft_opendir(char *path)
{
	DIR		*res;

	res = opendir(path);
	if (res == NULL)
	{
		ft_putstr(path);
		ft_putendl(":");
		perror("ft_ls");
	}
	return (res);
}

int				ft_readlvln(t_list *files, char *opts)
{
	DIR			*fd_dir;
	t_list		*lvln;
	char		*path;

	while (files != NULL)
	{
		if (ft_strcmp(((t_filedata *)(files->content))->name, ".") == 0 ||
				ft_strcmp(((t_filedata *)(files->content))->name, "..") == 0)
			files = files->next;
		else if (opts[2] == '-' && (((t_filedata *)(files->content))->name)[0] == '.')
			files = files->next;
		else if ((((t_filedata *)(files->content))->rights)[0] == 'd')
		{
			ft_putstr("\n");
			path = ft_buildpath((t_filedata *)(files->content));
			if (path == NULL)
				return (0);
			fd_dir = ft_opendir(path);
			if (fd_dir != NULL)
			{
				lvln = ft_readlvl0(fd_dir, path, opts);
				closedir(fd_dir);
				ft_putstr(path);
				ft_putendl(":");
				ft_putfldtlst(lvln, opts);
				ft_readlvln(lvln, opts);
				ft_freelst(&lvln);
			}
			free(path);
		}
		files = files->next;
	}
	return (1);
}

/*
** attention aux protections et liberations
*/

void		ft_readinput(t_list *dir_lst, char *opts, char ftype)
{
	DIR					*fd;
	t_list				*lvl0;
	char				*path;
	int					p;

	p = 1;
	if (dir_lst->next == NULL)
		p = -1;
	while (dir_lst != NULL)
	{
		if (((((t_filedata *)(dir_lst->content))->rights)[0] == ftype && ftype != 'l') ||
			((((t_filedata *)(dir_lst->content))->rights)[0] == 'l' && ftype == 'd'))// ||
//			((((t_filedata *)(dir_lst->content))->rights)[0] == 'd' && ftype == 'l'))
		{
//			ft_putnbrendl(((t_filedata *)(dir_lst->content))->nblocks);
			if (p == 1)
			{
				ft_putstr(((t_filedata *)(dir_lst->content))->input_name);
				ft_putendl(":");
			}
			if (ftype == 'd' || ftype == 'l')
			{
				fd = ft_opendir(((t_filedata *)(dir_lst->content))->path);
				if (fd == NULL)
					return ;
				path = ft_normpath(((t_filedata *)(dir_lst->content))->path);
				((t_filedata *)(dir_lst->content))->path = path;
				if (path == NULL)
					return ;
				lvl0 = ft_readlvl0(fd, path, opts);
				if (lvl0 == NULL)
					return ;
				closedir(fd);
				ft_putfldtlst(lvl0, opts);
				if (opts[1] == 'R')
					ft_readlvln(lvl0, opts);
				ft_freelst(&lvl0);
				if (dir_lst->next != NULL)
					ft_putchar('\n');
			}
		}
		dir_lst = dir_lst->next;
	}
}

int			main(int argc, char **argv)
{
	int					i;
	char				*types;
	char				*opts;
	t_list				*dir_lst;

	types = "-dlbcsp";
	opts = ft_parseopts(argc, argv);
	if (opts == NULL)
		return (-1);
	dir_lst = ft_readpathinput(argc, argv, opts);
	if (dir_lst == NULL)
		return (-1);
	dir_lst = ft_exists(dir_lst);
	if (dir_lst == NULL)
		return (-1);
	i = 0;
	while (types[i])
	{
		ft_readinput(dir_lst, opts, types[i]);
		i++;
	}
	free(opts);
	ft_freelst(&dir_lst);
	//	ft_putfldtlst(dir_lst);
/*
	while (dir_lst != NULL)
	{
		ft_putendl(((t_filedata *)(dir_lst->content))->input_name);
		if ((((t_filedata *)(dir_lst->content))->rights)[0] == 'd')
		{
			fd = opendir(((t_filedata *)(dir_lst->content))->path);
			if (fd == NULL)
				return (-1);
			path = ft_normpath(((t_filedata *)(dir_lst->content))->path);
			if (path == NULL)
				return (-1);
			lvl0 = ft_readlvl0(fd, path, opts);
			if (lvl0 == NULL)
				return (-1);
			closedir(fd);
			ft_putfldtlst(lvl0);
			free(path);
			if (opts[1] == 'R')
				ft_readlvln(lvl0, opts);
			ft_freelst(&lvl0);
		}
		dir_lst = dir_lst->next;
	}
*/

}

/*
** attributs etendus
** erreur dans la boucle dans -R /dev
** liberations et protections
*/

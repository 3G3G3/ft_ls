#include "ft_ls.h"

t_list			*ft_fldt_listnew(struct dirent *dir, char *path)
{
	t_filedata		*fldt;
	t_list			*res;

	fldt = ft_getstat(dir, path);
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

t_list			*ft_readlvl0(DIR *fd_dir, char *path, char *opts)
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
		ft_putendl("there");
		return (NULL);
	}
	res = ft_fldt_listnew(dir, path);
	while ((dir = readdir(fd_dir)) != NULL)
	{
		if (opts[2] == 'a' || (dir->d_name)[0] != '.')
		{
			tmp_res = ft_fldt_listnew(dir, path);
			if (tmp_res == NULL)
			{
				ft_freelst(&res);
				return (NULL);
			}
			ft_lstsortedadd(&res, tmp_res, opts);
//		ft_putfldtlst(res);
//		ft_lstadd(&res, tmp_res);
		}
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
			lvln = ft_readlvl0(fd_dir, path, opts);
			closedir(fd_dir);
			ft_putfldtlst(lvln);
			ft_readlvln(lvln, opts);
			ft_freelst(&lvln);
			free(path);
		}
		files = files->next;
	}
	return (1);
}


int main(int argc, char **argv)
{
//	DIR					*fd_dir;
	t_list				*dir_lst;
//	char				*path;
	char				*opts;
//	struct dirent		*dir;

	opts = ft_parseopts(argc, argv);
/*
		path = "libft";
		path = argv[1];
	fd_dir = opendir(path);
	if (fd_dir == NULL)
	{
		ft_putendl("ici");
		return (0);
	}

	dir = readdir(fd_dir);
	if (dir == NULL)
	{
		ft_putendl("bigmistake");
		return (-1);
	}
	ft_putendl(dir->d_name);
	if (dir->d_type == DT_REG)
		ft_putendl("file");
	if (dir->d_type == DT_DIR)
		ft_putendl("dir");
	closedir(fd_dir);

	dir_lst = ft_readlvl0(fd_dir, path, opts);
	closedir(fd_dir);
	if (dir_lst == NULL)
		ft_putendl("regarde moi");
	ft_putfldtlst(dir_lst);
	if (opts[1] == 'R')
		ft_readlvln(dir_lst, opts);
	free(opts);
	if (dir_lst != NULL)
	{
		ft_putendl("la");
		ft_freelst(&dir_lst);
	}
*/
	dir_lst = ft_readpathinput(argc, argv, opts);
	while (dir_lst != NULL)
	{
		ft_putendl(dir_lst->content);
		dir_lst = dir_lst->next;
	}
	return (1);
}

/*
## prendre en compte quand plusieurs repertoires en input,
##		le tri s'oppere en premier lieu sur ces repertoires
*/

/*
## attention quand l'input est un fichier et non un dossier,
## il faut en autre verifier s'il existe bien.
*/

/*
## repertoire sans les droits?
*/

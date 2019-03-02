#include "ft_ls.h"

int			ft_getindexfirstpath(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	return (i);
}

DIR			*ft_opendir(char *path)
{
	DIR		*res;

	res = opendir(path);
	if (res == NULL)
	{
		ft_putendl("wrong directory");
		return (NULL);
	}
	return (res);
}

int		ft_getlastslash(char *str)
{
	int		i;

	if (str == NULL)
		return (-2);
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '/')
		i--;
	return (i);
}

char	**ft_fillpathnfile(char *str, int i)
{
	char	**res;
	char	*rpath;
	char	*rfile;

	ft_putnbrendl(i);
	res = (char **)ft_memalloc(3 * sizeof(char *));
	if (ft_strcmp(str, "..") == 0)
	{
		ft_putendl("testreussi");
		rpath = ft_strdup("../");
	}
	else if (i == -1)
		rpath = ft_strdup("./");
	else
		rpath = ft_strnew((i + 1) * sizeof(char));
	rfile = ft_strnew((ft_strlen(str) - i) * sizeof(char));
	if (res == NULL || rpath == NULL || rfile == NULL)
	{
		if (res != NULL)
			free(res);
		if (rpath != NULL)
			free(rpath);
		if (rfile != NULL)
			free(rfile);
		return (NULL);
	}
	if (rpath[0] != '.')
		str = ft_memcpy(rpath, str, i + 1);
	if (ft_strncmp(rpath, "/", 1) != 0 && ft_strncmp(rpath, "./", 2) != 0 &&
			ft_strncmp(rpath, "~/", 2) != 0 && ft_strncmp(rpath, "../", 3) != 0)
		rpath = ft_strjoin("./", rpath);
	res[0] = rpath;
	str = ft_memcpy(rfile, str, (ft_strlen(str) - i));
	res[1] = rfile;
	ft_putendl(rpath);
	return (res);
}

char	**ft_getpathnfile(char *str)
{
	int		i;
	char	**res;

	i = ft_getlastslash(str);
	if (i == -2)
		return (NULL);
	res = ft_fillpathnfile(str, i);
//	ft_putendl(res[1]);
	return (res);
}


t_list		*ft_readpathinput(int argc, char **argv, char *opts)
{
	int		i;
	char		**ptmp;
	t_list		*tmp;
	t_list		*res;

	opts = (void *)opts;
	i = ft_getindexfirstpath(argc, argv);
	if (i == argc)
		return (ft_lstnew("./", 3 * sizeof(char)));
	ft_putendl(argv[i]);
	ptmp = ft_getpathnfile(argv[i]);
	if (ptmp == NULL)
		return (NULL);
	ft_putendl(ptmp[0]);
	res = ft_lstnew(ptmp[0], ft_strlen(ptmp[0]) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i++;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		ptmp = ft_getpathnfile(argv[i]);
		if (ptmp == NULL)
			return (NULL);
		ft_putendl(ptmp[0]);
		tmp = ft_lstnew(ptmp[0], ft_strlen(ptmp[0]) * sizeof(char));
		if (tmp == NULL)
			return (NULL);
		ft_lstadd(&res, tmp);
		i++;
	}
	return (res);
}

/*
t_list		*ft_readpathinput(int argc, char **argv, char *opts)
{
	int			i;
	DIR			*fd_dir;
	t_list		*tmp;
	t_list		*res;

	opts = (void *)opts;
	i = ft_getindexfirstpath(argc, argv);
	if (i == argc)
	{
		fd_dir = ft_opendir("./");
		if (fd_dir == NULL)
			return (NULL);
		res = ft_lstnew(fd_dir, sizeof(DIR));
		if (res == NULL)
			return (NULL);
		return (res);
	}
	fd_dir = ft_opendir(argv[i]);
	if (fd_dir == NULL)
			return (NULL);
	res = ft_lstnew(fd_dir, sizeof(DIR));
		if (res == NULL)
			return (NULL);
	i++;
	while (i < argc)
	{
		fd_dir = ft_opendir(argv[i]);
		if (fd_dir == NULL)
				return (NULL);
		tmp = ft_lstnew(fd_dir, sizeof(DIR));
		if (tmp == NULL)
		{
//			free(res) et le contenu;
			return (NULL);
		}
//		ft_lstsortedadd(&res, tmp, opts);
		i++;
	}
	return (res);
}
*/

/*
## creer une struture avec le fd le nom et la date de mofication, sur laquelle on opere le tri,
## on se complique la vie (a remonte dans l'arborescence) seulement si l'option -t est appelee
## on peut alors afficher le message d'rreur si le dossier ou le fichiern'existe pas
## on parcourt ensuite la liste de fd quel'on lit avec la structure du main.
*/

/*
## parser de path :
reperer les fichiers du repertoire courant des autres (. .. oup presence /)
chacun ont un traitement different: construction d'une liste qui remplace de readlvl0
les courant : lecture du repertoire courant et v2rification de la correspondance.
les autres: ont les lits directs, en s'y deplacant mainis s'arretant a l'avant dernier du chemin normalise./ (parcourt de la chaine de charactere par la fin)
on stocke les data de chaque fichiers dans une liste. 

## si pas de \ et diff2rent de ..: on est dans le repertoire courant
## sinon on se deplance
*/

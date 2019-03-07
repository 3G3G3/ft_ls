#include "ft_ls.h"

char	**ft_filldirnfile(char *str, int i)
{
	char	**res;
	char	*rdir;
	char	*rfile;

	res = (char **)ft_memalloc(3 * sizeof(char *));
	if (ft_strcmp(str, "..") == 0)
		rdir = ft_strdup("../");
	else if (i == -1)
		rdir = ft_strdup("./");
	else
		rdir = ft_strnew((i + 1) * sizeof(char));
	rfile = ft_strnew((ft_strlen(str) - i) * sizeof(char));
	if (res == NULL || rdir == NULL || rfile == NULL)
	{
		if (res != NULL)
			free(res);
		if (rdir != NULL)
			free(rdir);
		if (rfile != NULL)
			free(rfile);
		return (NULL);
	}
	if (rdir[0] != '.')
		rdir = ft_memcpy(rdir, str, i + 1);
	if (ft_strncmp(rdir, "/", 1) != 0 && ft_strncmp(rdir, "./", 2) != 0 &&
			ft_strncmp(rdir, "~/", 2) != 0 && ft_strncmp(rdir, "../", 3) != 0)
		rdir = ft_strjoin("./", rdir);
	res[0] = rdir;
	if (ft_strcmp(str, "..") != 0 && ft_strcmp(str, ".") != 0)
		rfile = ft_memcpy(rfile, str + 1 + i, (ft_strlen(str) - i));
	res[1] = rfile;
	return (res);
}

char	**ft_getdirnfile(char *str)
{
	int		i;
	char	**res;

	i = ft_getlastslash(str);
	if (i == -2)
		return (NULL);
	res = ft_filldirnfile(str, i);
	return (res);
}

t_list		*ft_createelem(char *path)
{
	char			**tmp;
	t_filedata		*fldt;
	t_list			*res;

	if ((tmp = ft_getdirnfile(path)) == NULL)
		return (NULL);
	if ((fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata))) == NULL)
		return (NULL);
	if ((res = ft_lstnew(fldt, sizeof(t_filedata))) == NULL)
		return (NULL);
	if ((((t_filedata *)(res->content))->dir = tmp[0]) == NULL)
		return (NULL);
	if ((((t_filedata *)(res->content))->name = tmp[1]) == NULL)
		return (NULL);
	if ((((t_filedata *)(res->content))->path = ft_strjoin(tmp[0],
															tmp[1])) == NULL)
		return (NULL);
	if ((((t_filedata *)(res->content))->input_name = ft_strdup(path)) == NULL)
		return (NULL);
	if ((((t_filedata *)(res->content))->rights = ft_strnew(10)) == NULL)
		return (NULL);
	return (res);
// libérer les précèdents en cas d'échec de mallloc
}


t_list		*ft_readpathinput(int argc, char **argv)
{
	int		i;
	t_list		*tmp;
	t_list		*res;
	t_filedata	*fldt;

	i = ft_getindexfirstpath(argc, argv);
	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	if (i == argc)
		return (ft_createelem("./"));
	res = ft_createelem(argv[i]);
	if (res == NULL)
		return (NULL);
	i++;
	while (i < argc)
	{
		tmp = ft_createelem(argv[i]);
		if (tmp == NULL)
			return (NULL);
//		liberer le début de liste
		ft_lstsortedadd(&res, tmp, "----i");
		i++;
	}
	return (res);
}

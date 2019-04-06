/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsepath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:35:33 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 20:23:48 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_dirnfilemalloc(char *str, int i)
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
	res[0] = rdir;
	res[1] = rfile;
	return (res);
}

char		**ft_filldirnfile(char *str, int i)
{
	char	**res;
	char	*tmp;

	res = ft_dirnfilemalloc(str, i);
	if (res == NULL)
		return (NULL);
	if (res[0][0] != '.')
		res[0] = ft_memcpy(res[0], str, i + 1);
	if (ft_strncmp(res[0], "/", 1) != 0 && ft_strncmp(res[0], "./", 2) != 0 &&
		ft_strncmp(res[0], "~/", 2) != 0 && ft_strncmp(res[0], "../", 3) != 0)
	{
		tmp = res[0];
		res[0] = ft_strjoin("./", tmp);
		free(tmp);
	}
	if (ft_strcmp(str, "..") != 0 && ft_strcmp(str, ".") != 0)
		res[1] = ft_memcpy(res[1], str + 1 + i, (ft_strlen(str) - i));
	return (res);
}

char		**ft_getdirnfile(char *str)
{
	int		i;
	char	**res;

	i = ft_getlastslash(str);
	if (i == -2)
		return (NULL);
	res = ft_filldirnfile(str, i);
	return (res);
}

t_list		*ft_addpath(t_list **lst, char *path, char *opts)
{
	t_list		*tmp;

	tmp = ft_createelem(path);
	if (tmp == NULL)
	{
		ft_freelst(lst);
		return (NULL);
	}
//	if (opts[3] == '-' && opts[4] == '-')
//		ft_lstsortedadd(lst, tmp, "----i");
//	else if (opts[3] == 'r' && opts[4] == '-')
//		ft_lstsortedadd(lst, tmp, "---ri");
//	else
		ft_lstsortedadd(lst, tmp, opts);
	return (*lst);
}

t_list		*ft_readpathinput(int argc, char **argv, char *opts)
{
	int			i;
	t_list		*res;

	i = ft_getindexfirstpath(argc, argv);
	if (i == argc)
		return (ft_createelem("./\0"));
	res = ft_createelem(argv[i]);
	if (res == NULL)
		return (NULL);
	i++;
	while (i < argc)
	{
		res = ft_addpath(&res, argv[i], opts);
		i++;
	}
	return (res);
}

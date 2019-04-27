/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseinputpath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:36:45 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 19:55:35 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_parseinputparse(char *path)
{
	char	*res;

	if (ft_strcmp(path, "~") == 0 || ft_strcmp(path, ".") == 0
	|| ft_strcmp(path, "..") == 0)
		res = ft_strjoin(path, "/");
	else
		res = ft_strdup(path);
	return (res);
}

t_list		*ft_createemptyfile(void)
{
	t_filedata	*fldt;
	t_list		*file;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	fldt->path = ft_strdup("\0");
	fldt->name = ft_strdup("\0");
	fldt->abs_time = 0;
	fldt->rights = ft_strdup("0");
	if (fldt->path == NULL || fldt->name == NULL || fldt->rights == NULL)
	{
		ft_freeobjs(fldt->path, fldt->name, fldt->rights, NULL);
		ft_freefldt(&fldt);
		return (NULL);
	}
	file = ft_createfile(fldt);
	return (file);
}

t_list		**ft_lstlstmalloc(void)
{
	t_list		**res;

	res = (t_list **)ft_memalloc(3 * sizeof(t_list *));
	if (res == NULL)
		return (NULL);
	res[0] = ft_createemptyfile();
	res[1] = ft_createemptyfile();
	res[2] = ft_createemptyfile();
	if (res[0] == NULL || res[1] == NULL || res[2] == NULL)
	{
		if (res + 2 != NULL)
			ft_freelst(res + 2);
		if (res + 1 != NULL)
			ft_freelst(res + 1);
		if (res != NULL)
			ft_freelst(res);
		free(res);
		return (NULL);
	}
	return (res);
}

void		ft_readpathinput_body(char *path, t_list **res, char *opts)
{
	t_list		*tmp;

	tmp = ft_newfile(path, opts);
	if (tmp != NULL
		&& (((t_filedata *)(tmp->content))->rights)[0] == 'd')
		ft_lstsortedadd(res + 2, tmp, opts);
	else if (tmp == NULL)
	{
		tmp = ft_newunvalid(path);
		if (tmp != NULL)
			ft_lstsortedadd(res, tmp, "------");
	}
	else if (tmp != NULL)
		ft_lstsortedadd(res + 1, tmp, opts);
}

t_list		**ft_readpathinput(int argc, char **argv, char *opts)
{
	int			i;
	char		*path;
	t_list		**res;

	i = ft_getindexfirstpath(argc, argv);
	res = ft_lstlstmalloc();
	if (res == NULL)
		return (NULL);
	if (i == argc)
		ft_lstsortedadd(res + 2, ft_newfile(NULL, opts), opts);
	while (i < argc)
	{
		path = ft_parseinputparse(argv[i]);
		if (path != NULL)
			ft_readpathinput_body(path, res, opts);
		i++;
	}
	return (res);
}

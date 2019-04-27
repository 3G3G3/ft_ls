/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:03:50 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 20:24:00 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_normpath(char *path)
{
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoinfree(&path, "/");
	return (path);
}

char		*ft_buildpath(t_filedata *fldt)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = ft_strjoin(fldt->dir, "/");
	if (tmp1 == NULL)
		return (NULL);
	tmp2 = ft_strjoinfree(&tmp1, fldt->name);
	if (tmp2 == NULL)
	{
		free(tmp1);
		return (NULL);
	}
	return (tmp2);
}

int			ft_getlastslash(char *str)
{
	int		i;

	if (str == NULL)
		return (-2);
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '/')
		i--;
	return (i);
}

int			ft_getindexfirstpath(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	return (i);
}

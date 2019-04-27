/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:53:21 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 15:53:53 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_newunvalid(char *path)
{
	t_list		*res;
	t_filedata	*fldt;

	fldt = (t_filedata *)ft_memalloc(sizeof(t_filedata));
	if (fldt == NULL)
		return (NULL);
	fldt->name = path;
	res = ft_createfile(fldt);
	if (res == NULL)
		free(fldt);
	return (res);
}

void		ft_putunvalid(t_list *files)
{
	while (files != NULL)
	{
		if (ft_strcmp(((t_filedata *)(files->content))->name, "\0") != 0)
		{
			write(1, "ft_ls: ", 7);
			ft_putstr(((t_filedata *)(files->content))->name);
			write(1, ": No such file or directory\n", 28);
		}
		files = files->next;
	}
}

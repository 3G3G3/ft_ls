/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:23:43 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 19:51:14 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_pexists(char *path, t_filedata *fldt)
{
	t_stat		*stats;

	if (path == NULL || fldt->rights == NULL)
		return (0);
	stats = NULL;
	stats = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (stats == NULL)
		return (0);
	if (lstat(path, stats) == -1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		fldt->abs_time = 0;
		free(stats);
		if (g_output < 1)
			g_output = 1;
		return (0);
	}
	fldt->abs_time = stats->st_mtime;
	ft_convertrights(stats, fldt->rights);
	free(stats);
	return (1);
}

/*
**  this functions aims at freeing the unvalid file of the list until it finds
**  one valid
*/

void		ft_freeunvalid(t_list **lst)
{
	t_list		*tmpc;

	tmpc = *lst;
	while (*lst != NULL && ft_pexists(((t_filedata *)((*lst)->content))->path,
								((t_filedata *)((*lst)->content))) == 0)
	{
		*lst = (*lst)->next;
		ft_freefldt((t_filedata **)(&(tmpc->content)));
		free(tmpc);
		tmpc = *lst;
	}
}

t_list		*ft_exists(t_list *lst)
{
	t_filedata		*fldt;
	t_list			*tmpc;
	t_list			*tmpm;
	t_list			*res;

	ft_freeunvalid(&lst);
	res = lst;
	tmpm = lst;
	while (lst != NULL)
	{
		tmpc = lst;
		fldt = (t_filedata *)(lst->content);
		ft_pexists(fldt->path, fldt);
		lst = lst->next;
		if (fldt->abs_time == 0)
		{
			tmpm->next = lst;
			ft_freefldt((t_filedata **)(&(tmpc->content)));
			free(tmpc);
		}
		else
			tmpm = tmpc;
	}
	return (res);
}

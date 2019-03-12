/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:43:56 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/12 17:23:57 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_freefldt(t_filedata *fldt)
{
	if (fldt->input_name != NULL)
		free(fldt->input_name);
	if (fldt->dir != NULL)
		free(fldt->dir);
	if (fldt->name != NULL)
		free(fldt->name);
	if (fldt->path != NULL)
		free(fldt->path);
	if (fldt->rights != NULL)
		free(fldt->rights);
	if (fldt->uid != NULL)
		free(fldt->uid);
	if (fldt->gid != NULL)
		free(fldt->gid);
	free(fldt);
	fldt = NULL;
}

void		ft_freelst(t_list **elem)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *elem;
	while (tmp1 != NULL)
	{
		ft_freefldt(tmp1->content);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = NULL;
		tmp1 = tmp2;
	}
}

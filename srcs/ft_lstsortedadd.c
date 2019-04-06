/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortedadd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:05:06 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 20:11:52 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_pasciisort(t_list *elem1, t_list *elem2)
{
	return (ft_strcmp(((t_filedata *)(elem1->content))->input_name,
						((t_filedata *)(elem2->content))->input_name));
}

int			ft_asciisort(t_list *elem1, t_list *elem2)
{
	return (ft_strcmp(((t_filedata *)(elem1->content))->name,
						((t_filedata *)(elem2->content))->name));
}

int			ft_tmsort(t_list *elem1, t_list *elem2)
{
	if (((t_filedata *)(elem2->content))->abs_time -
						((t_filedata *)(elem1->content))->abs_time != 0)
	{
		return (((t_filedata *)(elem2->content))->abs_time -
						((t_filedata *)(elem1->content))->abs_time);
	}
	return (ft_asciisort(elem1, elem2));
}

void		ft_getsortfunc(char *opt, int (**f)(t_list *elem1, t_list *elem2))
{
	if (opt[4] == 't')
		*f = ft_tmsort;
	else if (opt[4] == 'i')
		*f = ft_pasciisort;
	else
		*f = ft_asciisort;
}

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opts)
{
	t_list		*tmp;
	t_list		*melem;
	int			(*f)(t_list *elem1, t_list *elem2);

	ft_getsortfunc(opts, &f);
	tmp = *lst;
	if ((opts[3] == '-' && f(tmp, elem) > 0) ||
		(opts[3] == 'r' && f(tmp, elem) < 0))
	{
		ft_lstadd(lst, elem);
		return ;
	}
	melem = tmp;
	tmp = tmp->next;
	while (tmp != NULL && !((opts[3] == '-' && f(tmp, elem) > 0) ||
							(opts[3] == 'r' && f(tmp, elem) < 0)))
	{
		melem = tmp;
		tmp = tmp->next;
	}
	ft_lstaddi(&melem, elem);
}

#include "ft_ls.h"


int		ft_asciisort(t_list *elem1, t_list *elem2)
{
	return (ft_strcmp(((t_filedata *)(elem1->content))->name,
						((t_filedata *)(elem2->content))->name));
}

int		ft_rasciisort(t_list *elem1, t_list *elem2)
{
	return (-1 * ft_asciisort(elem1, elem2));
}

int		ft_tmsort(t_list *elem1, t_list *elem2)
{
	if (((t_filedata *)(elem2->content))->abs_time -
						((t_filedata *)(elem1->content))->abs_time != 0)
	{
		return (((t_filedata *)(elem2->content))->abs_time -
						((t_filedata *)(elem1->content))->abs_time);
	}
	return (ft_asciisort(elem1, elem2));
}

int		ft_rtmsort(t_list *elem1, t_list *elem2)
{
	return (-1 * ft_tmsort(elem1, elem2));
}

void		ft_getsortfunc(char *opt, int (**f)(t_list *elem1, t_list *elem2))
{
	if (opt[3] == 'r' && opt[4] == '-')
		*f = ft_rasciisort;
	else if (opt[3] == '-' && opt[4] == 't')
		*f = ft_tmsort;
	else if (opt[3] == 'r' && opt[4] == 't')
		*f = ft_rtmsort;
	else
		*f = ft_asciisort;
}

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opt)
{
	t_list		*tmp;
	t_list		*melem;
	int			(*f)(t_list *elem1, t_list *elem2);

	ft_getsortfunc("----t", &f);
	opt = (void *)opt;
	tmp = *lst;
//	ft_putnbrendl(ft_defaultsort(tmp, elem));
	if (f(tmp, elem) > 0)
	{
		ft_lstadd(lst, elem);
		return ;
	}
	melem = tmp;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (f(tmp, elem) > 0)
		{
			ft_lstaddi(&melem, elem);
			return ;
		}
		melem = tmp;
		tmp = tmp->next;
	}
	ft_lstaddi(&melem, elem);
	return ;
}

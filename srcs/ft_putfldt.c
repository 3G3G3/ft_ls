#include "ft_ls.h"

void            ft_putfldt(t_filedata *fldt)
{
	ft_putstr(fldt->path);
	ft_putstr(" : ");
	ft_putstr(fldt->name);
	ft_putstr(" : ");
	ft_putstr(fldt->rights);
	ft_putendl(";");
}

void			ft_putfldtlst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putfldt(lst->content);
		lst = lst->next;
	}
}

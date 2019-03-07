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
}

void		ft_freelst(t_list **elem)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *elem;
	while (tmp1 != NULL)
	{
		ft_freefldt(tmp1->content);
		free(tmp1->content);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = NULL;
		tmp1 = tmp2;
	}
}


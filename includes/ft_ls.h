#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "libft.h"

typedef struct stat t_stat;

typedef	struct		s_filedata
{
	char			*name;
	char			*rights;
	char			*path;
}					t_filedata;

void		ft_putfldt(t_filedata *fldt); // pourra être supprimée à terme

void		ft_putfldtlst(t_list *lst);

void ft_freelst(t_list **elem);

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include "libft.h"

typedef struct stat t_stat;

typedef	struct		s_filedata
{
	char			*name;
	char			*rights;
	char			*path;
	time_t			abs_time;
}					t_filedata;

void		ft_putfldt(t_filedata *fldt); // pourra être supprimée à terme

void		ft_putfldtlst(t_list *lst);

void		ft_freelst(t_list **elem);

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opt);

char		**ft_parseinput(int argc, char **argv);

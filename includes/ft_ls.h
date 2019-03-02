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

t_filedata	* ft_getstat(struct dirent *dir, char *path);

void		ft_freelst(t_list **elem);

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opts);

char		*ft_parseopts(int argc, char **argv);

t_list		*ft_readpathinput(int argc, char **argv, char *opts);

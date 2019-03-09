#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include "libft.h"

typedef struct stat t_stat;

typedef	struct		s_filedata
{
	char			*input_name;
	char			*path;
	char			*dir;
	char			*name;
	char			*rights;
	time_t			abs_time;
}					t_filedata;

int			ft_getindexfirstpath(int argc, char **argv);

char		*ft_normpath(char *path);

char		*ft_buildpath(t_filedata *fldt);

char		**ft_getdirnfile(char *str);

int			ft_getlastslash(char *str);

t_list		*ft_createelem(char *path);

void		ft_putfldt(t_filedata *fldt); // pourra être supprimée à terme

void		ft_putfldtlst(t_list *lst);

void		ft_convertrights(t_stat *stats, char *rights);

t_filedata	* ft_getstat0(struct dirent *dir, char *path);

void		ft_freefldt(t_filedata *fldt);

void		ft_freelst(t_list **elem);

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opts);

char		*ft_parseopts(int argc, char **argv);

t_list		*ft_readpathinput(int argc, char **argv, char *opts);

t_list		*ft_exists(t_list *lst);

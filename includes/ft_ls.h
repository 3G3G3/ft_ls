#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include "libft.h"

typedef struct stat t_stat;

typedef	struct		s_len
{
	size_t		lnlinks;
	size_t		luid;
	size_t		lgid;
	size_t		lsize;
	size_t		lmajor;
	size_t		lminor;
	blksize_t	nblocks;
}					t_len;

typedef	struct		s_filedata
{
	char			*input_name;
	char			*path;
	char			*dir;
	char			*name;
	char			*rights;
	time_t			abs_time;
	nlink_t			nlinks;
	char 			*uid;
	char			*gid;
	off_t			size;
	blksize_t		nblocks;
	char			*pfile;
	unsigned int	spmaj;
	unsigned int	spmin;
}					t_filedata;

int			ft_getindexfirstpath(int argc, char **argv);

char		*ft_normpath(char *path);

char		*ft_buildpath(t_filedata *fldt);

char		**ft_getdirnfile(char *str);

int			ft_getlastslash(char *str);

t_list		*ft_createelem(char *path);

void		ft_putfldt(t_filedata *fldt, char *opts, t_len *sizes); // pourra être supprimée à terme

void		ft_putfldtlst(t_list *lst, char *opts);

t_filedata	*ft_getlongopt(t_filedata *fldt, t_stat * stats, char *path);

void		ft_convertrights(t_stat *stats, char *rights);

t_filedata	*ft_getstat0(struct dirent *dir, char *path, char *opts);

void		ft_freefldt(t_filedata *fldt);

void		ft_freelst(t_list **elem);

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opts);

char		*ft_parseopts(int argc, char **argv);

t_list		*ft_readpathinput(int argc, char **argv, char *opts);

t_list		*ft_exists(t_list *lst);

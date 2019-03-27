#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include "libft.h"
#include <sys/xattr.h>

typedef struct stat t_stat;

typedef	struct		s_len
{
	size_t		lino;
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
	unsigned int	ino;
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

size_t		ft_uintlen(unsigned int n);

void		ft_getuint(unsigned int n, char *buf);

size_t		ft_llen(long n);

void		ft_getl(long n, char *buf);

void		ft_getdate(time_t tm, char *buf);

t_len		*ft_getsizes(t_list *lst, char *opts);

void		ft_putfldt(t_filedata *fldt, char *opts, t_len *sizes);

void		ft_putfldtlst(t_list *lst, char *opts);

t_filedata	*ft_getlongopt(t_filedata *fldt, t_stat * stats, char *path);

void		ft_convertrights(t_stat *stats, char *rights);

t_filedata	*ft_getstat0(struct dirent *dir, char *path, char *opts);

void		ft_freefldt(t_filedata **fldt);

void		ft_freelst(t_list **elem);

void		ft_lstsortedadd(t_list **lst, t_list *elem, char *opts);

char		*ft_parseopts(int argc, char **argv);

t_list		*ft_readpathinput(int argc, char **argv, char *opts);

t_list		*ft_exists(t_list *lst);

t_list		*ft_fldt_listnew(struct dirent *dir, char *fdir, char *opts);

DIR			*ft_opendir(char *path);

t_list		*ft_readlvl0(DIR *fd_dir, char *fdir, char *opts);

void		ft_readlvln(t_list *files, char *opts);

void		ft_readinput(t_list *dir_lst, char *opts, char ftype);

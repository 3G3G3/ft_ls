/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:41:58 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 16:03:42 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include "libft.h"
# include <sys/xattr.h>
# include <errno.h>

# ifndef OUTPUT
#  define OUTPUT

int					g_output;
# endif

typedef struct stat	t_stat;

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
	char			*uid;
	char			*gid;
	off_t			size;
	blksize_t		nblocks;
	char			*pfile;
	unsigned int	spmaj;
	unsigned int	spmin;
}					t_filedata;

int					ft_getindexfirstpath(int argc, char **argv);

char				*ft_normpath(char *path);

char				*ft_buildpath(t_filedata *fldt);

int					ft_getlastslash(char *str);

t_list				*ft_createfile(t_filedata *fldt);

size_t				ft_uintlen(unsigned int n);

void				ft_getuint(unsigned int n, char *buf);

size_t				ft_llen(long n);

void				ft_getl(long n, char *buf);

void				ft_getdate(time_t tm, char *buf);

t_len				*ft_getsizes(t_list *lst, char *opts);

void				ft_puttot(blksize_t nblocks);

void				ft_putunvalid(t_list *lst);

void				ft_putfldtlst(t_list *lst, char *opts);

t_filedata			*ft_getlongopt(t_filedata *fldt, t_stat *stats, char *path);

void				ft_convertrights(t_stat *stats, char *rights);

t_filedata			*ft_convertstats(t_filedata *fldt,
						t_stat *stats, char *opts);

t_filedata			*ft_getstat(char *path, char *opts);

void				ft_freeobjs(void *obj1, void *obj2, void *obj3, void *obj4);

void				ft_freefldt(t_filedata **fldt);

void				ft_freelst(t_list **elem);

void				ft_lstsortedadd(t_list **lst, t_list *elem, char *opts);

char				*ft_parseopts(int argc, char **argv);

t_list				**ft_readpathinput(int argc, char **argv, char *opts);

t_list				*ft_newunvalid(char *path);

t_list				*ft_newfile(char *path, char *opts);

DIR					*ft_opendir(char *path);

t_list				*ft_readlvl0(DIR *fd_dir, char *fdir, char *opts,
						blksize_t *nblocks);

void				ft_browselvln(t_list *files, char *opts);

void				ft_browseinput(t_list *dir_lst, char *opts, size_t iput);

#endif

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
	t_stat			*stats;
}					t_filedata;


#include "ft_ls.h"

t_filedata		*ft_getlongopt(t_filedata *fldt, t_stat *stats, char *path)
{
	struct passwd	*uid;
	struct group	*gid;

	fldt->nlinks = stats->st_nlink;
	fldt->size = stats->st_size;
	uid = getpwuid(stats->st_uid);
	fldt->uid = ft_strdup(uid->pw_name);
	if (fldt->uid == NULL)
		return (NULL);
	gid = getgrgid(stats->st_gid);
	fldt->gid = ft_strdup(gid->gr_name);
	if (fldt->gid == NULL)
	{
		free(fldt->uid);
		return (NULL);
	}
	if ((fldt->rights)[0] == 'l')
	{
		fldt->pfile = ft_strnew(63);
		if (readlink(path, fldt->pfile, 63) == -1)
			perror("Error reading link by readlink");
	}
	return (fldt);
}

#include "ft_ls.h"

ssize_t		ft_listxattr(char *path, char **buf)
{
	ssize_t	len;

	len = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (len == -1)
		return (-1);
	if (len == 0)
		return (0);
	*buf = ft_memalloc(sizeof(char) * len);
	if (buf == NULL)
		return (-1);
	len = listxattr(path, *buf, len, XATTR_NOFOLLOW);
	if (len == -1)
	{
		free(*buf);
		return (-1);
	}
	return (len);
}

ssize_t		ft_getxattr(char *path, char *name, char **buf)
{
	ssize_t	len;

	len = getxattr(path, name, NULL, 0, 0, XATTR_NOFOLLOW);
	if (len == -1)
		return (-1);
	if (len == 0)
		return (0);
	*buf = ft_memalloc(sizeof(char) * len);
	if (buf == NULL)
		return (-1);
	len = getxattr(path, name, *buf, len, 0, XATTR_NOFOLLOW);
	if (len == -1)
	{
		free(*buf);
		return (-1);
	}
//	ft_putlong(len);
//	ft_putstr(*buf);
	return (len);
}

void	ft_putlistxattr(char *path)
{
	ssize_t		len;
	char		*buf_l;
	char		*buf_g;

	buf_l = NULL;
	buf_g = NULL;
	len = ft_listxattr(path, &buf_l);
	ft_putnbrendl(len);
	if (len > -1)
	{
		ft_putendl("@");
	}
	len = ft_getxattr(path, buf_l, &buf_g);
	ft_putnbrendl(len);
	if (len > -1)
	{
		ft_putendl("+");
		free(buf_g);
	}
	free(buf_l);
}


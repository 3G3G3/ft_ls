/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:29:52 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/08 15:43:21 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(const int fd, size_t buff_size)
{
	int		r;
	char	*tmp;
	char	*buf;
	char	*res;

	buf = ft_strnew(buff_size);
	res = ft_strnew(buff_size);
	if (!buf || !res)
		return (NULL);
	res = (read(fd, buf, buff_size) > 0) ? ft_strcpy(res, buf) : NULL;
	if (res == NULL)
		return (NULL);
	buf = ft_memset(buf, '\0', buff_size + 1);
	while ((r = read(fd, buf, buff_size)) > 0)
	{
		tmp = res;
		res = ft_strjoin(res, buf);
		ft_strdel(&tmp);
		if (!res)
			return (NULL);
		buf = ft_memset(buf, '\0', buff_size + 1);
	}
	ft_strdel(&buf);
	res = (r == -1) ? NULL : res;
	return (res);
}

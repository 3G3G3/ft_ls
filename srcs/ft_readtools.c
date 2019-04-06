/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:21:33 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/23 19:28:44 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR				*ft_opendir(char *path)
{
	DIR		*res;
	char	*err_msg;

	res = opendir(path);
	if (res == NULL)
	{
//		ft_putstr(path);
//		ft_putendl(":");
		err_msg = ft_strjoin("ft_ls: ", path);
		if (err_msg == NULL)
			return (NULL);
		if (errno == 13)
			g_output = 1;
		perror(err_msg);
		free(err_msg);
	}
	return (res);
}

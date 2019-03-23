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

	res = opendir(path);
	if (res == NULL)
	{
		ft_putstr(path);
		ft_putendl(":");
		perror("ft_ls");
	}
	return (res);
}

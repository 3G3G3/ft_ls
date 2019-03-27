/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:17:51 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/27 10:53:49 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_getlst(int argc, char **argv, char *opts)
{
	t_list				*dir_lst;

	dir_lst = ft_readpathinput(argc, argv, opts);
	if (dir_lst == NULL)
		return (NULL);
	dir_lst = ft_exists(dir_lst);
	return (dir_lst);
}

int			main(int argc, char **argv)
{
	int					i;
	char				*types;
	char				*opts;
	t_list				*dir_lst;

	types = "-dlbcsp";
	opts = ft_parseopts(argc, argv);
	if (opts == NULL)
		return (-1);
	dir_lst = ft_getlst(argc, argv, opts);
	if (dir_lst == NULL)
	{
		free(opts);
		return (-1);
	}
	i = 0;
	while (types[i])
	{
		ft_readinput(dir_lst, opts, types[i]);
		i++;
	}
	free(opts);
	ft_freelst(&dir_lst);
}

/*
** attributs etendus
** erreur dans la boucle dans -R /dev
** liberations et protections
*/

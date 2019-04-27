/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:17:51 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/06 19:58:16 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	char				*types;
	char				*opts;
	t_list				**parsed_input;

	types = "-clbspd";
	g_output = 0;
	opts = ft_parseopts(argc, argv);
	if (opts == NULL)
		return (1);
	parsed_input = ft_readpathinput(argc, argv, opts);
	if (parsed_input == NULL)
	{
		free(opts);
		return (1);
	}
	ft_putunvalid(*parsed_input);
	ft_putfldtlst(*(parsed_input + 1), opts);
	ft_browseinput(*(parsed_input + 2), opts, ft_lstlen(*parsed_input)
		+ ft_lstlen(*(parsed_input + 1)));
	free(opts);
	ft_freelst(parsed_input + 2);
	ft_freelst(parsed_input + 1);
	ft_freelst(parsed_input);
	free(parsed_input);
	return (g_output);
}


// check affigage date
/*
** fuites mémoires
*/

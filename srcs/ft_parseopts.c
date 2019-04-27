/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseopts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:44:31 by grgauthi          #+#    #+#             */
/*   Updated: 2019/04/27 19:57:23 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getopt(char input, char *buf)
{
	if (input == 'l')
		buf[0] = 'l';
	else if (input == 'R')
		buf[1] = 'R';
	else if (input == 'a')
		buf[2] = 'a';
	else if (input == 'r')
		buf[3] = 'r';
	else if (input == 't')
		buf[4] = 't';
	else if (input == 'i')
		buf[6] = 'i';
	else
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(input);
		ft_putendl("\nusage: [-alrRti] [files ...]");
		free(buf);
		return (NULL);
	}
	return (buf);
}

char		*ft_readopt(char *input, char *buf)
{
	int		i;

	i = 1;
	while (input[i])
	{
		buf = ft_getopt(input[i], buf);
		if (buf == NULL)
			return (NULL);
		i++;
	}
	return (buf);
}

char		*ft_parseopts(int argc, char **argv)
{
	int		i;
	char	*opts;

	opts = (char *)ft_strnew(sizeof(char) * 7);
	opts = ft_memset(opts, '-', 6);
	if (opts == NULL)
		return (NULL);
	i = 1;
	while (i < argc && argv[i][0] == '-' && opts != NULL)
	{
		if (ft_strcmp(argv[i], "--") != 0)
			opts = ft_readopt(argv[i], opts);
		i++;
	}
	if (opts != NULL)
		opts[5] = 'n';
	return (opts);
}

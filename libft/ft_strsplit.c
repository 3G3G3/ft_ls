/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:27:37 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 19:50:38 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) ||
				(i > 0 && str[i - 1] == c && str[i] != c))
			count++;
		i++;
	}
	return (count);
}

static int		ft_wl(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t		i;
	int			n;
	char		**r;

	if (!str)
		return (NULL);
	r = (char **)ft_memalloc(sizeof(*r) * (ft_count_words(str, c) + 1));
	if (!r)
		return (NULL);
	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if ((i == 0 && str[i] != c) ||
				(i > 0 && str[i - 1] == c && str[i] != c))
		{
			r[n] = ft_strsub(str, i, ft_wl(str + i, c));
			if (!r[n])
				return (NULL);
			n++;
		}
		i++;
	}
	r[n] = NULL;
	return (r);
}

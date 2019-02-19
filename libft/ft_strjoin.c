/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:39:39 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 10:50:27 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		l1;
	size_t		l2;
	size_t		i;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = ft_strnew(l1 + l2);
	if (!res)
		return (NULL);
	while (i < l1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		res[i] = s2[i - l1];
		i++;
	}
	return (res);
}

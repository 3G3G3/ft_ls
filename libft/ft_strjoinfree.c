/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:05:12 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 11:12:39 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, const char *s2)
{
	char	*tmp;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	tmp = s1;
	res = ft_strjoin(s1, s2);
	if (!res)
		return (NULL);
	ft_strdel(&tmp);
	return (res);
}

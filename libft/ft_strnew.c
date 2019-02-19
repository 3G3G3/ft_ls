/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:19:50 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/20 17:06:12 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)ft_memalloc(size + 1);
	if (!res)
		return (NULL);
	while (i < size + 1)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

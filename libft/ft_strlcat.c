/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:17:18 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 17:48:26 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	len_dest;
	unsigned int	j;
	size_t			res;

	len_dest = ft_strlen(dest);
	j = 0;
	if (size <= len_dest)
		res = ft_strlen(src) + size;
	else
	{
		while (src[j] != '\0' && j < size - len_dest - 1)
		{
			dest[len_dest + j] = src[j];
			j++;
		}
		dest[len_dest + j] = '\0';
		res = len_dest + ft_strlen(src);
	}
	return (res);
}

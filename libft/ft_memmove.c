/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:43:06 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 17:44:19 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*t;

	if (dst > src)
	{
		t = (unsigned char *)dst;
		i = len;
		while (i)
		{
			t[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}

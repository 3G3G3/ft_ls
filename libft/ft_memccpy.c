/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:00:37 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/17 17:13:30 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*t;
	size_t				i;

	i = 0;
	t = (unsigned char *)dst;
	while (i < n)
	{
		t[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] != (unsigned char)c)
			i++;
		else
			return (dst + i + 1);
	}
	return (NULL);
}

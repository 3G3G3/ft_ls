/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:33:46 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/24 17:28:52 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*t;

	t = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		t[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

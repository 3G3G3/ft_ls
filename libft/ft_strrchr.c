/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:34:45 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/20 14:35:01 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memchr_rev(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = n - 1;
	t = (unsigned char *)s;
	while (t[i] && t[i] != (unsigned char)c && i < n)
		i--;
	if (((unsigned char *)s)[i] == (unsigned char)c && i < n)
		return (t + i);
	return (NULL);
}

char		*ft_strrchr(const char *s, int c)
{
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	return (ft_memchr_rev(s, c, ft_strlen(s)));
}

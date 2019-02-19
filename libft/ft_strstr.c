/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 21:34:01 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/24 16:43:22 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_test(const char *haystack, const char *needdle, int pos)
{
	size_t	i;

	i = 0;
	while (haystack[pos + i] == needdle[i] && haystack[pos + i] != '\0')
		i++;
	if (needdle[i] == '\0')
		return (1);
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (ft_test(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

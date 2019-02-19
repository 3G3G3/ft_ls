/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:05:49 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/24 16:43:18 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_test(const char *haystack, const char *needle, int pos)
{
	size_t	i;

	i = 0;
	while (haystack[pos + i] == needle[i] && haystack[pos + i] != '\0')
		i++;
	if (needle[i] == '\0')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len)
{
	size_t		i;

	if (needle[0] == '\0' && haystack[0] == '\0')
		return ("\0");
	if (needle[0] == '\0' && haystack[0] != '\0')
		return ((char *)haystack);
	if (haystack[0] == '\0' && needle[0] != '\0')
		return (0);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (i + ft_strlen(needle) < len + 1 &&
				ft_test(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

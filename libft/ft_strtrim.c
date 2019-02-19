/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:18:35 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 18:50:42 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		end;
	char		*res;

	if (!s)
		return (NULL);
	end = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		end++;
		i--;
	}
	if (end == ft_strlen(s))
	{
		res = ft_strnew(0);
		return (res);
	}
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	res = ft_strsub(s, i, ft_strlen(s) - i - end);
	if (!res)
		return (NULL);
	return (res);
}

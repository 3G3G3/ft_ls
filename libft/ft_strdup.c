/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:34:19 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/08 11:11:34 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
	{
		res = (char *)malloc(sizeof(*res) * (i + 1));
		res[0] = '\0';
		return (res);
	}
	while (str[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(*res) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

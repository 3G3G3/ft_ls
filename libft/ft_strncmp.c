/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:04:39 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 18:26:50 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		index;
	int			res;

	if (n > 0)
	{
		index = 0;
		while (index < n &&
				(unsigned char)s1[index] == (unsigned char)s2[index] &&
				s1[index] != '\0')
			index++;
		if (index == n)
			res = (unsigned char)s1[index - 1] - (unsigned char)s2[index - 1];
		else
			res = (unsigned char)s1[index] - (unsigned char)s2[index];
	}
	else
		res = 0;
	return (res);
}

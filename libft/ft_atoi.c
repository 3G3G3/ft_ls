/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 12:12:39 by grgauthi          #+#    #+#             */
/*   Updated: 2018/08/03 14:08:40 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_initialize(const char *nptr, int *sign)
{
	size_t		start_position;

	start_position = 0;
	*sign = 1;
	while (nptr[start_position] == ' ' ||
			(nptr[start_position] >= 9 && nptr[start_position] <= 13))
		start_position++;
	if (nptr[start_position] == '-')
	{
		*sign = -1;
		start_position++;
	}
	else if (nptr[start_position] == '+')
		start_position++;
	return (start_position);
}

int				ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	res = 0;
	i = ft_initialize(nptr, &sign);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

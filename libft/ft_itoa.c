/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:15:31 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/24 17:17:19 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_exp(int n)
{
	int		e;

	e = 0;
	while (-9 > n || 9 < n)
	{
		n = n / 10;
		e++;
	}
	return (e);
}

static int		ft_power10(int n)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	while (i < n)
	{
		res = 10 * res;
		i++;
	}
	return (res);
}

static int		ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*res;

	res = ft_strnew(ft_exp(n) + ft_isneg(n) + 1);
	if (!res)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (ft_isneg(n))
		res[0] = '-';
	res[ft_isneg(n)] = n / ft_power10(ft_exp(n)) + '0';
	i = ft_exp(n) + ft_isneg(n);
	n = -1 * (2 * ft_isneg(n) - 1) * n;
	while (0 < i)
	{
		res[i] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	return (res);
}

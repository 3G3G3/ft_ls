/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:48:48 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/27 10:27:22 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ft_uintlen(unsigned int n)
{
	size_t	res;

	res = 1;
	while ((n = n / 10) != 0)
		res++;
	return (res);
}

void		ft_getuint(unsigned int n, char *buf)
{
	size_t		i;

	i = ft_uintlen(n) - 1;
	if (n == 0)
		buf[0] = '0';
	while (n > 0)
	{
		buf[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

size_t		ft_llen(long n)
{
	size_t	res;

	res = 1;
	while ((n = n / 10) != 0)
		res++;
	return (res);
}

void		ft_getl(long n, char *buf)
{
	size_t		i;

	i = ft_uintlen(n) - 1;
	if (n == 0)
		buf[0] = '0';
	while (n > 0)
	{
		buf[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

void		ft_puttot(blksize_t nblocks)
{
	ft_putstr("total ");
	ft_putllong(nblocks);
	ft_putchar('\n');
}

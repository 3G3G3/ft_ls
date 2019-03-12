/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:15:16 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/12 19:19:36 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putllong(long long  nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (-(nb / 10) != 0)
			ft_putnbr(-(nb / 10));
		ft_putchar(-(nb % 10) + '0');
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:15:39 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/17 17:15:49 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (-(nb / 10) != 0)
			ft_putnbr_fd(-(nb / 10), fd);
		ft_putchar_fd(-(nb % 10) + '0', fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
	}
}

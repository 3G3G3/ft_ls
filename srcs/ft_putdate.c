/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:47:41 by grgauthi          #+#    #+#             */
/*   Updated: 2019/03/23 17:31:27 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putddyyyy(char *date, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 10)
	{
		if (i >= 8 && i <= 10)
		{
			buf[j] = date[i];
			j++;
		}
		i++;
	}
	i = 4;
	while (i <= 23)
	{
		if ((i >= 4 && i <= 7) || (i >= 19 && i <= 23))
		{
			buf[j] = date[i];
			j++;
		}
		i++;
	}
}

void		ft_putddmmhh(char *date, char *buf)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (i <= 15)
	{
		buf[j] = date[i];
		j++;
		i++;
	}
}

void		ft_getdate(time_t tm, char *buf)
{
	char		*date;
	time_t		t;

	date = ctime(&tm);
	t = time(0);
	if (date == NULL || t == -1)
	{
		perror("error asking for actual time in time()");
		return ;
	}
	if (t - tm < 15552000)
		ft_putddmmhh(date, buf);
	else
		ft_putddyyyy(date, buf);
}

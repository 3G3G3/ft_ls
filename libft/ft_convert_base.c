/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:08:57 by grgauthi          #+#    #+#             */
/*   Updated: 2018/08/14 17:51:19 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_base(char *base)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	res = 1;
	while (base[i] && res == 1)
	{
		j = i + 1;
		while (base[j] && res == 1)
		{
			if (base[i] == base[j])
				res = 0;
			j++;
		}
		i++;
	}
	return (res);
}

int		ft_b_to_dec(char *n, char *base)
{
	int			i;
	size_t		j;
	int			res;

	i = 0;
	res = 0;
	while (n[i])
	{
		j = 0;
		while (n[i] != base[j] && base[j])
			j++;
		if (j == ft_strlen(base))
			return (0);
		else
			res = ft_strlen(base) * res + j;
		i++;
	}
	return (res);
}

char	*ft_dec_to_b(int n, char *base)
{
	char	*res;

	res = (char *)malloc(sizeof(*res) * 32);
	if (res == NULL)
		return (NULL);
	if (n < (int)ft_strlen(base))
	{
		res[0] = base[n];
		res[1] = '\0';
	}
	else
	{
		res = ft_dec_to_b(n / ft_strlen(base), base);
		res[ft_strlen(res)] = base[n % ft_strlen(base)];
		res[ft_strlen(res) + 1] = '\0';
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;

	if (ft_check_base(base_from) && ft_check_base(base_to))
		res = ft_dec_to_b(ft_b_to_dec(nbr, base_from), base_to);
	else
		res = NULL;
	return (res);
}

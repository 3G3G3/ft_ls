/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:04:54 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 11:05:09 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_init(void const *ptr, size_t len)
{
	t_list		*res;

	if (len > 0)
	{
		res = ft_lstnew(ptr, sizeof(char));
		if (!res)
			return (NULL);
	}
	else
	{
		res = ft_lstnew(NULL, 0);
		if (!res)
			return (NULL);
	}
	return (res);
}

t_list			*ft_str2lst(void *ptr, size_t len)
{
	size_t		i;
	t_list		*u;
	t_list		*res;

	if (!ptr || !((unsigned char *)ptr)[0])
		return (NULL);
	res = ft_init(ptr, len);
	if (!res)
		return (NULL);
	i = 1;
	while ((i < len) && ((unsigned char *)ptr)[i])
	{
		u = ft_lstnew(ptr + i, sizeof(char));
		if (!u)
			return (NULL);
		ft_lstadd_fifo(&res, u);
		i++;
	}
	return (res);
}

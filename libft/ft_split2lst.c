/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:05:25 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/01 17:02:28 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_init(void const *split)
{
	t_list		*res;

	if (split)
	{
		res = ft_lstnew(split, sizeof(char) * (ft_strlen(split) + 1));
		if (!res)
			return (NULL);
		((char *)(res->content))[ft_strlen(split)] = '\0';
	}
	else
	{
		res = ft_lstnew(NULL, 0);
		if (!res)
			return (NULL);
	}
	return (res);
}

t_list			*ft_split2lst(char **split)
{
	size_t		i;
	t_list		*u;
	t_list		*res;

	if (!split)
		return (NULL);
	res = ft_init(*split);
	if (!res)
		return (NULL);
	i = 1;
	while (split[i])
	{
		u = ft_lstnew(split[i], sizeof(char) * (ft_strlen(split[i])) + 1);
		if (!u)
			return (NULL);
		((char *)(u->content))[ft_strlen(split[i])] = '\0';
		ft_lstadd_fifo(&res, u);
		i++;
	}
	return (res);
}

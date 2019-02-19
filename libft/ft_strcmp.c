/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:12:50 by grgauthi          #+#    #+#             */
/*   Updated: 2018/11/27 18:26:24 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while ((unsigned char)s1[index] == (unsigned char)s2[index] &&
			(unsigned char)s1[index] != '\0')
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

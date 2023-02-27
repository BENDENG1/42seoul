/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:05:39 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 13:34:42 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	s_len = ft_strlen(s);
	if (s != 0 && f != 0)
	{
		while (i < s_len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}

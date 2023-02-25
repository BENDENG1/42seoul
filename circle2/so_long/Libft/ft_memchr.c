/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:53:33 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/13 20:02:55 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	while (num--)
	{
		if (*tmp == (unsigned char)value)
			return (tmp);
		tmp++;
	}
	return (0);
}

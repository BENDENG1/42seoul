/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:33:43 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 14:10:58 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*tmp_d;
	const char	*tmp_s;

	tmp_d = dest;
	tmp_s = src;
	if (!dest && !src)
		return (0);
	while (num-- > 0)
	{
		*tmp_d++ = *tmp_s++;
	}
	return (dest);
}

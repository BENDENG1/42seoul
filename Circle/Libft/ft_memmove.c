/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:31:58 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 13:25:46 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*tmp_d;
	const char	*tmp_s;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest <= src)
	{
		tmp_d = dest;
		tmp_s = src;
		while (num--)
			*tmp_d++ = *tmp_s++;
	}
	else
	{
		tmp_d = dest;
		tmp_s = src;
		tmp_d += (num - 1);
		tmp_s += (num - 1);
		while (num--)
			*tmp_d-- = *tmp_s--;
	}
	return (dest);
}

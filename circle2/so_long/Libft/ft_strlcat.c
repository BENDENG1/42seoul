/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:40:35 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/13 17:24:06 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_length;
	size_t	s_length;

	i = 0;
	d_length = ft_strlen(dest);
	s_length = ft_strlen(src);
	if (size < d_length)
		return (s_length + size);
	while (src[i] != '\0' && d_length + i + 1 < size)
	{
		dest[d_length + i] = src[i];
		i++;
	}
	if (d_length < size)
		dest[d_length + i] = '\0';
	return (s_length + d_length);
}

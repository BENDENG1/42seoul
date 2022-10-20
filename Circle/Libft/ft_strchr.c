/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:35:03 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 13:39:30 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int pos)
{
	while (*str != (unsigned char)pos)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:43:34 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 18:46:23 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int pos)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	while (str_len != 0 && str[str_len] != (char)pos)
	{
		str_len--;
	}
	if (str[str_len] == (char)pos)
		return ((char *)(str + str_len));
	return (0);
}

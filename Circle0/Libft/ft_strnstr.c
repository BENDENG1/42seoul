/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:05:21 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/13 20:28:06 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	find_i;

	i = 0;
	if (find[0] == '\0')
		return (&((char *)str)[0]);
	while (str[i] && i < len)
	{
		find_i = 0;
		if (find[find_i] == str[i + find_i])
		{
			while (find[find_i] && str[i + find_i])
			{
				if (find[find_i] != str[i + find_i] || (i + find_i) >= len)
					break ;
				find_i++;
			}
			if (find[find_i] == '\0')
				return (&((char *)str)[i]);
		}
		i++;
	}
	return (0);
}

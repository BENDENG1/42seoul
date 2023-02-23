/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:31:56 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/15 15:23:04 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		str_len;
	char	*m_str;

	i = 0;
	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	m_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!(m_str))
		return (0);
	while (str[i] != '\0')
	{
		m_str[i] = str[i];
		i++;
	}
	m_str[i] = 0;
	return (m_str);
}

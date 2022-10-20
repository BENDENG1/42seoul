/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:23:53 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/15 15:32:35 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	ft_memcpy(tmp, s1, s1_len);
	ft_memcpy(tmp + s1_len, s2, s2_len);
	tmp[s1_len + s2_len] = 0;
	return (tmp);
}

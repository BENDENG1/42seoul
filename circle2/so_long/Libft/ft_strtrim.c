/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:35:44 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/15 16:08:55 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (!s1)
		return (0);
	if (!s2)
		return (ft_strdup((char *)s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(s2, s1[start]))
		start++;
	while (s1[end -1] && ft_strchr(s2, s1[end - 1]))
	{
		if (end < 2)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1 + start, end - start + 1);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:41:41 by gyroh             #+#    #+#             */
/*   Updated: 2022/11/18 11:25:34 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (src[i])
		i++;
	temp = (char *)malloc(i * sizeof(char) + 1);
	if (!temp)
		return (0);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s || start < 0)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (len > str_len)
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:49:10 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/07 18:10:49 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = NULL;
	if (n == 0)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (arr == 0)
		return (NULL);
	while (i < n)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_free(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

static	size_t	ft_wordc(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
		(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_wordc(s, c) + 1));
	if (!arr)
		return (NULL);
	while (i < ft_wordc(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[i] = ft_strndup(&s[k], j - k);
		if (arr[i++] == 0)
			return (ft_free(arr));
	}
	arr[i] = NULL;
	return (arr);
}

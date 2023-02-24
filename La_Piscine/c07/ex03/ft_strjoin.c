/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:28:00 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/01 05:28:17 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	src_i;

	i = 0;
	src_i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[src_i] != '\0')
	{
		dest[i] = src[src_i];
		i++;
		src_i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*cat_arr(char *arr, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		arr = ft_strcat(arr, strs[i]);
		arr = ft_strcat(arr, sep);
		i++;
	}
	arr = ft_strcat(arr, strs[i]);
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char));
		arr[0] = 0;
		return (arr);
	}
	while (i < size)
		len += ft_strlen(strs[i++]);
	arr = (char *)malloc(len + (size - 1) * ft_strlen(sep) + 1);
	if (!arr)
		return (NULL);
	arr[0] = 0;
	arr = cat_arr(arr, strs, sep, size);
	return (arr);
}

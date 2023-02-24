/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:37:27 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/01 07:37:33 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_c(char find, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (find == charset[i])
			return (1);
		i++;
	}
	if (find == 0)
		return (1);
	return (0);
}

int	count_c(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((find_c(str[i + 1], charset) == 1 && find_c(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

void	ft_strcpy(char *dest, char *src, char *charset)
{
	int		i;

	i = 0;
	while (find_c(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	make_arr(char **arr, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (find_c(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (find_c(str[i + j], charset) == 0)
				j++;
			arr[k] = (char *)malloc(j + 1);
			ft_strcpy(arr[k], str + i, charset);
			i = i + j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	i = count_c(str, charset);
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (0);
	arr[i] = 0;
	make_arr(arr, str, charset);
	return (arr);
}

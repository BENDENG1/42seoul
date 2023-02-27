/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:46:15 by gyroh             #+#    #+#             */
/*   Updated: 2022/11/18 20:49:18 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
# include <fcntl.h>

int	findpos(const char *str,char pos)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == pos)
			return (i);
		i++;
	}
	return (0);
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
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	memcpy(tmp, s1, s1_len);
	memcpy(tmp + s1_len, s2, s2_len);
	tmp[s1_len + s2_len] = 0;
	return (tmp);
}


char *findnewline(int fd, char *arr)
{
	char	*sum;
	char	*tmp;
	int		i;

	sum = 0;
	while (findpos(arr, '\n') == 0)
	{
		i = read(fd, arr, BUFFER_SIZE);
		if (i < 0)
		{
			return (NULL);
		}
		arr[i] = 0;
		if (sum == 0)
			sum = strdup(arr);
		else
		{
			tmp = sum;
			sum = ft_strjoin(sum, arr);
			free(tmp);
		}
	}
	return (sum);
}

char *getnewline(char *lines)
{

}

char	*get_next_line(int fd)
{
	char	*arr;
	int		size;

	if (fd < 0)
		return(NULL);
	arr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	arr = findnewline(fd, arr); //문장들 다 구함
	if (arr == 0)
		return (0);
	arr = getnewline(arr);

	return (arr);
}


int main(){
	int a = open("txt", O_RDONLY);
	char *s = get_next_line(a);
	printf("s:%s\n", s);

}


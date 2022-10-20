/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:48:59 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 13:28:04 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!str || !f)
		return (0);
	i = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (i < len)
	{
		tmp[i] = f(i, str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

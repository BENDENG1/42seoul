/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#             */
/*   Updated: 2023/01/27 13:35:04 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			pm;
	long		num;
	int			i;
	int			j;

	pm = 1;
	num = 0;
	j = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pm *= -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		j++;
		i++;
		if ((j > 19 && pm == -1) || (num < 0 && pm == -1))
			return ((int)(-9223372036854775807 - 1));
		else if ((j > 19 && pm == 1) || (num < 0 && pm == 1))
			return ((int)9223372036854775807);
	}
	return ((int)num * pm);
}

int	ft_atoi_check(const char *str)
{
	int		len;
	char	c;
	int		i;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[0] == '0')
		return (0);
	i = 0;
	while (i < len)
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
			return (0);
		i++;
	}
	return (1);
}

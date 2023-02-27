/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:30:03 by gyroh             #+#    #+#             */
/*   Updated: 2022/07/15 16:48:46 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*tmp;
	long long	num;

	len = ft_getlen(n);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	tmp[len--] = 0;
	if (n < 0)
		num = -(long long)n;
	else
		num = (long long)n;
	while (len >= 0)
	{
		tmp[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (n < 0)
		tmp[0] = '-';
	return (tmp);
}

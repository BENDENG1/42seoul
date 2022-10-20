/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:03:11 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/20 21:26:44 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *tmp)
{
	int	length;

	length = 0;
	while (tmp[length])
	{
		length++;
	}
	return (length);
}

static char	*ft_convert(long long num, char *tmp, char *base, int length)
{
	int	base_len;

	base_len = ft_strlen(base);
	tmp[length--] = '\0';
	if (num == 0)
	{
		tmp[0] = base[0];
		return (tmp);
	}
	if (num < 0)
	{
		tmp[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		tmp[length--] = base[num % base_len];
		num /= base_len;
	}
	return (tmp);
}

void	*ft_itoa_base(long long n, char *arr, char *base)
{
	int			size;
	int			base_len;
	long long	tmp;

	size = 0;
	base_len = ft_strlen(base);
	tmp = n;
	if (tmp <= 0)
	{
		size++;
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		size++;
		tmp /= base_len;
	}
	return (ft_convert(n, arr, base, size));
}

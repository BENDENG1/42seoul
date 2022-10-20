/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:01:43 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/20 21:57:08 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long addr)
{
	int	len;

	if (addr == 0)
		return (1);
	len = 0;
	while (addr > 0)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

static void	ft_convert(unsigned long long addr, char *tmp)
{
	int	length;

	length = ft_ptr_len(addr) + 2;
	tmp[length] = '\0';
	tmp[0] = '0';
	tmp[1] = 'x';
	while (length >= 2)
	{
		tmp[length--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
}

int	print_ptr(unsigned long long addr)
{
	char	ptr[19];

	ft_convert(addr, ptr);
	return (print_str(ptr));
}

int	print_ten(long long num)
{
	char	ten[12];

	return (print_str(ten));
}

int	print_sixteen(long long num, int upper)
{
	char	sixteen[9];

	if (upper)
		ft_itoa_base(num, sixteen, "0123456789ABCDEF");
	else
		ft_itoa_base(num, sixteen, "0123456789abcdef");
	return (print_str(sixteen));
}

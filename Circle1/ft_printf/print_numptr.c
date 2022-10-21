/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:01:43 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/21 13:51:02 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_ptr(unsigned long long add, char *tmp)
{
	int					length;
	unsigned long long	tmp_addr;

	length = 0;
	tmp_addr = add;
	if (tmp_addr == 0)
		length = 1;
	while (tmp_addr > 0)
	{
		tmp_addr /= 16;
		length++;
	}
	length += 2;
	tmp[0] = '0';
	tmp[1] = 'x';
	tmp[length--] = '\0';
	while (length >= 2)
	{
		tmp[length--] = "0123456789abcdef"[add % 16];
		add /= 16;
	}
}

int	print_ptr(unsigned long long add)
{
	char	ptr[19];

	ft_convert_ptr(add, ptr);
	return (print_str(ptr));
}

int	print_ten(long long num)
{
	char	ten[12];

	ft_itoa_base(num, ten, "0123456789");
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

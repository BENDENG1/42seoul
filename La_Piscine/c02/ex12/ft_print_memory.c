/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:51:47 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/24 16:05:45 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_s(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_hex(unsigned long long num, int zero)
{
	char	*base;

	base = "0123456789abcdef";
	if (num < 16 && zero == 1)
		ft_putchar_s('0', 1);
	if (num >= 16)
	{
		ft_hex(num / 16, 0);
		ft_hex(num % 16, 0);
	}
	else
		ft_putchar_s(base[num], 1);
}

void	ft_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i < 16)
	{
		if (tmp < 16)
			ft_putchar_s('0', 1);
		tmp /= 16;
		i++;
	}
	ft_hex(addr, 0);
}

void	ft_data(unsigned char *arr, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar_s(' ', 1);
		if (i < size)
			ft_hex((unsigned long long) arr[i], 1);
		else if (i != 16)
			ft_putchar_s(' ', 2);
		i++;
	}
	ft_putchar_s(' ', 1);
	i = 0;
	while (i < size)
	{
		if (!(32 <= arr[i] && arr[i] <= 126))
			ft_putchar_s ('.', 1);
		else
			ft_putchar_s(arr[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned char		*arr;
	unsigned int		length;

	i = 0;
	arr = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			length = 16;
		else
			length = size % 16;
		ft_addr((unsigned long long)arr + (i * 16));
		ft_putchar_s(':', 1);
		ft_data(arr + (i * 16), length);
		ft_putchar_s('\n', 1);
		i++;
	}
	return (addr);
}


/*
void	addr(void *addr)
{
	unsigned char *up = (unsigned char *)&addr;
	for (int i = 7; i >= 0; i--)
	{
		up[i]
	}
}

*/

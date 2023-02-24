/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:29:07 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/16 11:40:12 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursive(int n, int *num)
{
	int	tmp;
	int	max;

	tmp = n - 1;
	max = 9;
	while (num[tmp] == max)
	{
		tmp -= 1;
		max -= 1;
	}
	num[tmp] += 1;
	while (tmp < n)
	{
		num[tmp + 1] = num[tmp] + 1;
		tmp += 1;
	}
}

void	ft_show(int n, int *num, int space)
{
	int	tmp;

	tmp = 0;
	if (space == 0)
	{
		write(1, ", ", 2);
	}
	while (tmp < n)
	{
		ft_putchar(num[tmp] + '0');
		tmp ++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;

	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	ft_show(n, num, 1);
	while (num[0] != 10 - n || num[n - 1] != 9)
	{
		if (num[n - 1] != 9)
			num[n - 1] += 1;
		else
			ft_recursive(n, num);
		ft_show(n, num, 0);
	}
}

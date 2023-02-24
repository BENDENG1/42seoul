/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:37:17 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/17 13:59:24 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_write((a / 10) + '0');
			ft_write((a % 10) + '0');
			write(1, " ", 1);
			ft_write((b / 10) + '0');
			ft_write((b % 10) + '0');
			if (a == 98 && b == 99)
			{
				return ;
			}
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

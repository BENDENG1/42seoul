/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:58:18 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/20 19:25:24 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	nbr_to_base(long long nbr, char *base, int length)
{
	int	i;

	i = 0;
	if (nbr >= length)
	{
		nbr_to_base(nbr / length, base, length);
		nbr_to_base(nbr % length, base, length);
	}
	else if (nbr < length)
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			length;
	long long	num;

	length = ft_strlen(base);
	if (base_check(base) == 0)
		return ;
	num = (long long)nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	nbr_to_base(num, base, length);
}

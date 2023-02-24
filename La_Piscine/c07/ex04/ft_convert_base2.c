/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:57:01 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/02 10:01:24 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	overlap(char *str, char find);
int	ft_getline(char *base);
int	ft_atoi_base(char *str, char *base);

int	num_size(unsigned int n, unsigned int base)
{
	if (n < base)
		return (1);
	return (1 + num_size(n / base, base));
}

int	get_size(int n, unsigned int *num, int base)
{
	int		i;

	if (n < 0)
	{
		*num = -n;
		i = num_size(*num, (unsigned int)base) + 1;
	}
	else
	{
		*num = n;
		i = num_size(*num, (unsigned int)base);
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*dest;
	unsigned int	num;
	int				base;
	int				i;
	int				n;

	n = ft_getline(base_from);
	base = ft_getline(base_to);
	if (!(n && base))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	i = get_size(n, &num, base);
	dest = malloc(i + 1);
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = base_to[num % base];
		num /= base;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

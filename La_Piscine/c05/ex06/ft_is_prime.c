/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:11:29 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/27 18:13:42 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else
	{
		while (i * i <= (unsigned int)nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

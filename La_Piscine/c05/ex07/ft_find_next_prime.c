/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:37 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/27 12:28:28 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 2)
		return (2);
	else
	{
		while (i * i <= (unsigned int)nb)
		{
			if (nb % i == 0)
			{
				nb++;
				i = 1;
			}
			i++;
		}
	}
	return (nb);
}

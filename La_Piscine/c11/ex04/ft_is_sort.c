/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:27:28 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/03 16:34:01 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	p;
	int	m;

	i = 0;
	p = 0;
	m = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			p++;
		else if (f(tab[i], tab[i + 1]) < 0)
			m++;
		i++;
	}
	if (p > 0 && m > 0)
		return (0);
	return (1);
}

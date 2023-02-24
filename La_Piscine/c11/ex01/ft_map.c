/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:26:29 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/03 10:09:30 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		arr[i] = (f(tab[i]));
		i++;
	}
	return (arr);
}

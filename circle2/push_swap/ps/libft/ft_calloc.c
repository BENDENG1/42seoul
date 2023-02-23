/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:51:00 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/28 15:36:58 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	tmp = (void *)malloc(count * size);
	if (tmp == 0)
		return (0);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}

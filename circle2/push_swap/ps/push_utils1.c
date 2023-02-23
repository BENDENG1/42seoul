/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:15 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/22 16:31:44 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a(t_deque *info)
{
	int		i;
	int		j;

	ft_a(info);
	i = info->size_a;
	j = 1;
	while (i > j)
	{
		insert_tail_a(info, info->arr[j]);
		j++;
	}
}

void	ft_stack(t_deque *info)
{
	make_a(info);
	if (info->size_a == 3)
	{
		case_num3_a(info);
		exit(0);
	}
	else if (info->size_a == 5)
	{
		case_num5_a(info);
		exit(0);
	}
}

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

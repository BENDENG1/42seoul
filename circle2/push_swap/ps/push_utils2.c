/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:31 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 19:03:31 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_deque *info)
{
	int	tmp;
	int	tmp1;

	tmp = info->size_a;
	tmp1 = info->size;
	while (tmp--)
	{
		if (info->size_a < 4)
			return ;
		if (info->top_a->val == info->sorted[tmp1 - 1]
			||info->top_a->val == info->sorted[tmp1 - 2]
			|| info->top_a->val == info->sorted[tmp1 - 3])
			ft_ra(info);
		else
			ft_pb(info);
	}
}

void	sort1(t_deque *info)
{
	int	pivot1;
	int	pivot2;
	int	tmp;

	pivot1 = info->sorted[info->size_a / 3];
	pivot2 = info->sorted[info->size_a / 3 * 2];
	tmp = info->size_a;
	while (tmp--)
	{
		if (info->top_a->val >= pivot2)
			ft_ra(info);
		else
		{
			ft_pb(info);
			if (info->top_b->val < pivot1)
				ft_rb(info);
		}
		if (info->size_a < 3)
			return ;
	}
	sort2(info);
}

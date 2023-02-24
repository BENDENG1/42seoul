/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:25 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 20:23:12 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_op1(t_deque *info, int *ra, int *rb, int *rrb)
{
	info->tmp = 0;
	info->location = 0;
	info->min = INT_MAX;
	info->rra1 = 0;
	*ra = 0;
	*rb = 0;
	*rrb = 0;
}

void	cal_op2(t_deque *info, int *ra, int *rb, int *rrb)
{
	if (info->location > (info->size_a) / 2)
	{
		info->location = (info->size_a) - (info->location);
		info->rra1 = info->location;
		*ra = 0;
	}
	if (info->idx > (info->size_b) / 2)
	{
		info->idx = info->size_b - info->idx;
		*rrb = info->idx;
		*rb = 0;
	}
	if (info->cnt > (info->location + info->idx))
	{
		info->cnt = (info->location) + (info->idx);
		info->ra = *ra;
		info->rb = *rb;
		info->rra = info->rra1;
		info->rrb = *rrb;
	}
}

void	calculate_op(int val, int idx, t_deque *info)
{
	int		ra;
	int		rb;
	int		rrb;
	t_node	*a_tmp_node;

	cal_op1(info, &ra, &rb, &rrb);
	rb = idx;
	info->idx = idx;
	a_tmp_node = info->top_a;
	while (a_tmp_node)
	{
		if (a_tmp_node->val > val && a_tmp_node->val < info->min)
		{
			info->min = a_tmp_node->val;
			info->location = info->tmp;
		}
		(info->tmp)++;
		a_tmp_node = a_tmp_node->next;
	}
	ra = info->location;
	cal_op2(info, &ra, &rb, &rrb);
}

void	find_min_op(t_deque *info)
{
	t_node	*b_tmp_node;
	int		idx;

	idx = 0;
	b_tmp_node = info->top_b;
	info->cnt = INT_MAX;
	while (idx < info->size_b)
	{
		calculate_op(b_tmp_node->val, idx, info);
		b_tmp_node = b_tmp_node->next;
		idx++;
	}
}

void	exec_op(t_deque *info)
{
	while (info->rb != 0)
	{
		ft_rb(info);
		(info->rb)--;
	}
	while (info->rrb != 0)
	{
		ft_rrb(info);
		(info->rrb)--;
	}
	while (info->ra != 0)
	{
		ft_ra(info);
		(info->ra)--;
	}
	while (info->rra != 0)
	{
		ft_rra(info);
		(info->rra)--;
	}
	ft_pa(info);
}

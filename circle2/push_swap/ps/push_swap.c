/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:59 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/07 18:06:01 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_deque *info)
{
	t_node	*tmp;
	t_node	*tmp1;

	free(info->arr);
	free(info->sorted);
	while (info->top_a->next)
	{
		tmp = info->top_a;
		tmp1 = info->top_a->next;
		free(tmp);
		info->top_a = tmp1;
	}
	free(info->top_a);
	free(info);
}

void	finish1(t_deque *info, int idx, int min, t_node *p_node)
{
	while (idx < info->size_a)
	{
		if (min == p_node->val)
			break ;
		idx++;
		p_node = p_node->next;
	}
	info->ra = idx;
	if (idx > (info->size_a) / 2)
	{
		idx = info->size_a - idx;
		info->rra = idx;
		info->ra = 0;
	}
}

void	finish(t_deque *info)
{
	t_node	*p_node;
	int		min;
	int		idx;

	min = info->sorted[0];
	idx = 0;
	p_node = info->top_a;
	info->rb = 0;
	info->rrb = 0;
	info->ra = 0;
	info->rra = 0;
	finish1(info, idx, min, p_node);
	exec_op(info);
}

void	sort(t_deque *info)
{
	sort1(info);
	case_num3_a(info);
	while (info->size_b)
	{
		find_min_op(info);
		exec_op(info);
	}
	finish(info);
}

int	main(int ac, char **av)
{
	t_deque	*info;

	info = (t_deque *)malloc(sizeof(t_deque));
	parsing(ac, av, info);
	ft_stack(info);
	sort(info);
	free_all(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_example.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:10 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 19:03:45 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_high(t_deque *info)
{
	int		i;
	t_node	*tmp_node;

	tmp_node = info->top_a;
	i = tmp_node->val;
	while (tmp_node)
	{
		if (tmp_node->val > i)
			i = tmp_node->val;
		tmp_node = tmp_node->next;
	}
	return (i);
}

void	case_num3_a(t_deque *info)
{
	int	i;

	i = ft_high(info);
	if (info->top_a->val == i)
		ft_ra(info);
	else if (info->top_a->next->val == i)
		ft_rra(info);
	if (info->top_a->val > info->top_a->next->val)
		ft_sa(info);
}

void	case_num5_a(t_deque *info)
{
	while (info->size_a != 3)
	{
		if (info->sorted[0] == info->top_a->val
			|| info->sorted[1] == info->top_a->val)
			ft_pb(info);
		else
			ft_ra(info);
	}
	if (info->top_b->val < info->top_b->next->val)
		ft_sb(info);
	case_num3_a(info);
	ft_pa(info);
	ft_pa(info);
}

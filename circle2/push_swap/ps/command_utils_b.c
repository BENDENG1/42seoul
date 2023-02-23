/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:02:16 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 13:26:48 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_deque *info)
{
	ft_swap(&info->top_b->val, &info->top_b->next->val);
	ft_putstr_fd("sb\n", 1);
}

void	ft_pa(t_deque *info)
{
	t_node	*tmp;

	if (info->size_b == 0)
		return ;
	else
		insert_head_a(info, info->top_b->val);
	if (info->size_b == 1)
		free(info->top_b);
	else
	{
		tmp = info->top_b->next;
		free(info->top_b);
		info->top_b = tmp;
		info->top_b->prev = 0;
	}
	(info->size_b)--;
	(info->size_a)++;
	ft_putstr_fd("pa\n", 1);
}

void	ft_rb(t_deque *info)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (info->size_b == 1)
		return ;
	tmp = info->top_b;
	tmp1 = info->top_b->next;
	info->top_b->next->prev = 0;
	info->top_b = tmp1;
	info->bottom_b->next = tmp;
	tmp->next = 0;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_deque *info)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (info->size_b == 1)
		return ;
	tmp = info->bottom_b;
	tmp1 = info->bottom_b->prev;
	tmp1->next = 0;
	tmp->next = info->top_b;
	tmp->prev = 0;
	info->top_b->prev = tmp;
	info->top_b = tmp;
	info->bottom_b = tmp1;
	ft_putstr_fd("rrb\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:15 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/24 16:37:53 by gyroh            ###   ########.fr       */
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
	// 애초에 필요없음..
	if (info->size_a == 3)
	{
		case_num3_a(info);
		//정상적으로 작동이 되는데 굳이? -> 수정요망
		exit(0);
	}
	////else if (info->size_a == 5)
	////{
	////	case_num5_a(info);
	////	exit(0);
	////}
}

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

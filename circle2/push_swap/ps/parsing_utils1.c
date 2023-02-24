/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:41 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 18:17:57 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnum(int **ret, int *j, char *av)
{
	int		i;
	int		k;
	int		c;
	char	**split;

	i = *j;
	c = 0;
	k = ft_wordc(av, ' ');
	split = ft_split(av, ' ');
	while (k > 0)
	{
		ret[0][i] = ft_atoi(split[c]);
		i++;
		k--;
		c++;
	}
	*j = i;
}

int	*make_arr(int ac, char **av, int size)
{
	int	*ret;
	int	i;
	int	j;

	i = 1;
	j = 0;
	ret = (int *)malloc(sizeof(int) * (size + 1));
	while (i < ac)
	{
		if (ft_check_array(av[i]) == 0)
			ret[j++] = ft_atoi(av[i]);
		else if (ft_check_array(av[i]) == 1)
			ft_putnum (&ret, &j, av[i]);
		i++;
	}
	i = 0;
	return (ret);
}

void	quick(int *arr, int L, int R)
{
	int	left;
	int	right;
	int	pivot;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (L < right)
		quick(arr, L, right);
	if (left < R)
		quick(arr, left, R);
}

void	ft_sort(int *i, int size, t_deque *info)
{
	int	*tmp;
	int	tmp1;
	int	tmp2;

	tmp = i;
	quick(tmp, 0, size - 1);
	error_overlap(tmp, size);
	info->sorted = tmp;
	tmp1 = info->size_a;
	tmp2 = 0;
	while (tmp1--)
	{
		if (info->arr[tmp1] == info->sorted[tmp1])
			tmp2++;
	}
	if (tmp2 == info->size_a)
		exit(0);
}

void	parsing(int ac, char **av, t_deque *info)
{
	int	*arr;
	int	size;
	int	*sorted;

	size = figures(ac, av);
	ft_check(ac, av);
	info->size_a = size;
	info->size = size;
	info->size_b = 0;
	arr = make_arr(ac, av, size);
	info->arr = arr;
	sorted = make_arr(ac, av, size);
	ft_sort(sorted, size, info);
}

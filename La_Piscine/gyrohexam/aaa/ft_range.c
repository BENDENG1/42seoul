/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:19:08 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/05 15:31:55 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*arr;
	int	range;
	int	i;

	i = 0;
	if (end >= start)
		range = end - start;
	else
		range = start - end;
	arr = (int *)malloc(sizeof(int) * (range + 1));
	if (end == start)
	{
		arr[0] = start;
	}
	else if (end > start)
	{
		while (end != start)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (end != start)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	return (arr);
}


#include <stdio.h>
int main(void)
{
	int *arr;
	int	i;

	i = 0;
	arr = ft_rrange(-2, 8);
	while (i < 10)
	{
		printf("%d", arr[i]);
		i++;
	}
}


/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
///////////////////////////////////////////////////

*/

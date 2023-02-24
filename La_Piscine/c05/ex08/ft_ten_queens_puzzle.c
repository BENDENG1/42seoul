/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:02:07 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/27 18:01:47 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(int *row, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (row[i] == row[pos] || (row[pos] - row[i]) == pos - i
			|| -(row[pos] - row[i]) == pos - i)
			return (0);
		i++;
	}
	return (1);
}

void	recursive(int *row, int col, int *cnt)
{
	int		i;
	char	c;

	row[col] = 0;
	while (row[col] < 10)
	{
		if (check(row, col) == 1)
		{
			if (col == 9)
			{
				i = 0;
				while (i < 10)
				{
					c = row[i] + '0';
					write(1, &c, 1);
					i++;
				}
				(*cnt)++;
				write(1, "\n", 1);
			}
			else
				recursive(row, col + 1, cnt);
		}
		row[col]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	row[10];
	int	cnt;

	row[0] = 0;
	cnt = 0;
	recursive(row, 0, &cnt);
	return (cnt);
}

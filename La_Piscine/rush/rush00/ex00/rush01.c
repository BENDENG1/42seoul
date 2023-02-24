/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:37:29 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/16 19:59:59 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rectangle(int col, int row, int end_col, int end_row)
{
	if (col == 1 && row == 1)
		ft_putchar('/');
	else if (col == end_col && row == 1)
		ft_putchar('\\');
	else if (col == 1 && row == end_row)
		ft_putchar('\\');
	else if (col == end_col && row == end_row)
		ft_putchar('/');
	else if (col == 1 || col == end_col)
		ft_putchar('*');
	else if (row == 1 || row == end_row)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			rectangle(j, i, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

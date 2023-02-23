/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:18 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 14:19:47 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void	error_overlap(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size-- > 1)
	{
		j = i + 1;
		if (arr[i] == arr[j])
			ft_print_error();
		i++;
	}
}

void	ft_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (ac > i)
	{
		j = ft_check_array(av[i]);
		if (j == 0)
			ft_check_array2(av[i]);
		else if (j == 1)
			ft_check_array3(av[i]);
		i++;
	}
}

void	ft_check_array2(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && flag == 1)
			ft_print_error();
		else if (str[i] == '-' || str[i] == '+')
			flag = 1;
		else if (!ft_isdigit(str[i]))
			ft_print_error();
		i++;
	}
}

void	ft_check_array3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
			ft_print_error();
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:50:17 by dllee             #+#    #+#             */
/*   Updated: 2023/02/23 14:23:01 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

void	ft_check_minus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
		{
			ft_print_error();
		}
		i++;
	}
}

int	ft_check_array(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			space++;
		else if (ft_isdigit(str[i]) && space == 1)
			return (1);
		if ((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1])))
			ft_print_error();
		i++;
	}
	return (0);
}

int	figures(int ac, char **av)
{
	int	i;
	int	ret;
	int	state;

	i = 1;
	ret = 0;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == 0)
			ret++;
		else if (state == 1)
		{
			ft_check_minus(av[i]);
			ret += ft_wordc(av[i], ' ');
		}
		i++;
	}
	return (ret);
}

int	ft_wordc(const char *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	ret;

	size = ft_strlen(s);
	i = 0;
	ret = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			ret++;
		i++;
	}
	if (i == 0)
		return (0);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:29:42 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 16:33:23 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		pm;
	size_t	ans;

	ans = 0;
	i = 0;
	pm = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return (pm * ans);
}

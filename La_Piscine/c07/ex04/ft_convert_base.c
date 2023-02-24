/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:56:40 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/02 10:01:17 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	overlap(char *str, char find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (find == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_getline(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (overlap(base + i + 1, base[i]) >= 0
			|| base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (9 <= base[i] && base[i] <= 13))
			return (0);
		i ++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	i;
	int	pm;
	int	length;

	pm = 1;
	num = 0;
	length = ft_getline(base);
	if (length == 0)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			pm *= -1;
	while (1)
	{
		i = overlap(base, *str);
		if (i < 0)
			break ;
		num = num * length + i;
		str++;
	}
	return (num * pm);
}

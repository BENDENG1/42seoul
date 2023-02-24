/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:33:26 by gyroh             #+#    #+#             */
/*   Updated: 2022/05/02 17:30:08 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (9 <= base[i] && base[i] <= 13))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_i_to_base(char find, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (find == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	i;
	int	pm;

	i = 0;
	pm = 1;
	num = 0;
	if (base_check_len(base) == 0)
		return (0);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm *= -1;
		i++;
	}
	while (1)
	{
		if (ft_i_to_base(str[i], base) == -1)
			break ;
		num = num * base_check_len(base) + ft_i_to_base(str[i], base);
		i++;
	}
	return (num * pm);
}

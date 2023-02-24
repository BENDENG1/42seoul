/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:30:38 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/18 11:41:30 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	find_i;

	i = 0;
	while (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		find_i = 0;
		while (str[i + find_i] == to_find[find_i])
		{
			find_i++;
			if (to_find[find_i] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

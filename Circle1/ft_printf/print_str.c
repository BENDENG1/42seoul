/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:25:43 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/20 22:15:59 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	length;

	if (!str)
		return (write(1, "(null)", 6));
	length = ft_strlen(str);
	return (write(1, str, length));
}

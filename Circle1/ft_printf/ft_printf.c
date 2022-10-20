/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:32:06 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/20 22:18:10 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	datatype_check(va_list *ap, char datatype)
{
	if (datatype == 'c')
		return (print_char(va_arg(*ap, int)));
	if (datatype == 's')
		return (print_str(va_arg(*ap, char *)));
	if (datatype == 'p')
		return (print_ptr(va_arg(*ap, unsigned long long)));
	if (datatype == 'd')
		return (print_ten(va_arg(*ap, int)));
	if (datatype == 'u')
		return (print_ten(va_arg(*ap, unsigned int)));
	if (datatype == 'x')
		return (print_sixteen(va_arg(*ap, unsigned int), 0));
	if (datatype == 'X')
		return (print_sixteen(va_arg(*ap, unsigned int), 1));
	if (datatype == '%')
		return (print_char('%'));
	else
		return (-1);
}

int	start_printf(va_list *ap, const char *format)
{
	int	i;
	int	cnt;
	int	check;

	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] != '%')
			check = write(1, &format[i], 1);
		else if (format[++i] != '\0')
			check = datatype_check(ap, format[i]);
		if (check < 0)
			return (-1);
		cnt += check;
		i++;
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		tmp;
	va_list	ap;

	va_start(ap, format);
	tmp = start_printf(&ap, format);
	va_end(ap);
	return (tmp);
}

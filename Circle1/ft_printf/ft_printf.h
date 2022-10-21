/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:37:39 by gyroh             #+#    #+#             */
/*   Updated: 2022/10/21 13:40:18 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		datatype_check(va_list *ap, char datatype);
int		start_printf(va_list *ap, const char *format);
int		ft_printf(const char *format, ...);
int		ft_strlen(char *tmp);
void	*ft_itoa_base(long long n, char *arr, char *base);
int		print_char(int c);
int		print_str(char *str);
int		print_ptr(unsigned long long addr);
int		print_ten(long long num);
int		print_sixteen(long long num, int upper);

#endif

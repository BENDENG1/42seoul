/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#             */
/*   Updated: 2023/01/27 15:58:50 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_print_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

void	ft_print_pid(int pid)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_print_success(int handler)
{
	(void)handler;
	ft_putstr_fd("Success\n", 1);
}

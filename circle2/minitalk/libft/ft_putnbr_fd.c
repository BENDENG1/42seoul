/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#             */
/*   Updated: 2023/01/27 11:10:48 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;
	unsigned char	n_tmp;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	n_tmp = (tmp % 10) + '0';
	write(fd, &n_tmp, 1);
}

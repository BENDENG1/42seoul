/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:36:03 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 13:29:25 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	s_len;

	if (fd < 0 || !s)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

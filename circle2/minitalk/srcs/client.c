/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#             */
/*   Updated: 2023/01/27 16:59:18 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	void	ft_send(int pid_server, char *str)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		bit = 1 << 7;
		while (bit)
		{
			if (str[i] & bit)
			{
				if (kill(pid_server, SIGUSR1) == -1)
					ft_print_error();
			}
			else
			{
				if (kill(pid_server, SIGUSR2) == -1)
					ft_print_error();
			}
			usleep(150);
			bit = bit >> 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
		ft_print_error();
	else
	{
		pid_server = ft_atoi(argv[1]);
		if (ft_atoi_check(argv[1]) == 0)
			ft_print_error();
		if (pid_server > 99998 || pid_server < 100)
			ft_print_error();
		if (!argv[1])
			ft_print_error();
		signal(SIGUSR1, ft_print_success);
		ft_send(pid_server, argv[2]);
	}
	return (0);
}

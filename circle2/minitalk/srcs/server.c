/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#             */
/*   Updated: 2023/01/27 16:00:04 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	void	ft_handler(int sign, siginfo_t *info, void *context)
{
	static unsigned char	str;
	static unsigned char	cnt;

	(void)context;
	++cnt;
	if (sign == SIGUSR1)
	{
		str = str << 1;
		str += 1;
	}
	else if (sign == SIGUSR2)
		str = str << 1;
	if (cnt == 8)
	{
		ft_putchar_fd(str, 1);
		if (str == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		cnt = 0;
		str = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_print_pid(pid);
	sig.sa_sigaction = ft_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:56 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:00:56 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg)
{
	printf("%s\n", msg);
	return (-1);
}

int	print_state(t_philo *philo, char *msg)
{
	long			time;
	struct timeval	cur;

	if (gettimeofday(&cur, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (-1);
	}
	time = calc_time(&(philo->monitor->start_time), &cur);
	pthread_mutex_lock(&(philo->monitor->m_finish));
	if (philo->monitor->finish_flag == 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_print));
		printf(msg, time, philo->id + 1);
		pthread_mutex_unlock(&(philo->monitor->m_print));
	}
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	return (0);
}

int	print_finish(t_philo *philo, int status)
{
	long			time;
	struct timeval	cur;

	pthread_mutex_lock(&(philo->monitor->m_finish));
	philo->monitor->finish_flag = 1;
	pthread_mutex_unlock(&(philo->monitor->m_finish));
	if (gettimeofday(&cur, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return (1);
	}
	time = calc_time(&(philo->monitor->start_time), &cur);
	pthread_mutex_lock(&(philo->monitor->m_print));
	if (status == DIE)
		printf("%ldms  %d  died\n", time, philo->id + 1);
	else if (status == FULL)
		printf("%ldms  all philosophers are full\n", time);
	pthread_mutex_unlock(&(philo->monitor->m_print));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:03 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:00:03 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo(t_monitor *monitor, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_destroy(&(monitor->philo[i].m_last_eat));
		pthread_mutex_destroy(&(monitor->philo[i].m_cnt_eat));
		i++;
	}
	free(monitor->philo);
	return (-1);
}

void	free_fork(t_monitor *monitor, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_destroy(&(monitor->m_fork[i]));
		i++;
	}
	free(monitor->fork);
	free(monitor->m_fork);
}

void	free_thread(t_monitor *monitor)
{
	int	i;
	int	after;

	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (monitor->thread[i] != NULL)
			pthread_join(monitor->thread[i], (void *)&after);
		i++;
	}
	free(monitor->thread);
}

int	free_all(t_monitor *monitor)
{
	free_philo(monitor, monitor->num_of_philo);
	free_fork(monitor, monitor->num_of_philo);
	pthread_mutex_destroy(&(monitor->m_print));
	return (0);
}

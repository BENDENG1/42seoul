/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:33:49 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/28 19:33:49 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_monitor *monitor)
{
	int		i;
	void	*target;

	monitor->thread = malloc(sizeof(pthread_t) * monitor->num_of_philo);
	if (monitor->thread == NULL)
		return (-1);
	if (monitor->num_of_philo == 1)
		target = routine_one;
	else
		target = routine;
	pthread_mutex_lock(&(monitor->m_start));
	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (pthread_create(&(monitor->thread[i]), NULL, \
			target, &(monitor->philo[i])) < 0)
			monitor->thread[i] = NULL;
		i++;
	}
	i = 0;
	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
	pthread_mutex_unlock(&(monitor->m_start));
	return (0);
}

int	main(int argc, char **argv)
{
	t_monitor	monitor;

	if (monitor_init(&monitor, argc, argv) < 0)
	{
		printf("Error : monitor_init\n");
		return (0);
	}
	if (mutex_init(&monitor) < 0)
	{
		printf("Error : mutex_init\n");
		return (free_all(&monitor));
	}
	if (create_philos(&monitor) < 0)
	{
		pthread_mutex_lock(&(monitor.m_finish));
		monitor.finish_flag = 2;
		pthread_mutex_unlock(&(monitor.m_finish));
		printf("Error : create_philos\n");
		free_thread(&monitor);
		return (free_all(&monitor));
	}
	start_eat(&monitor);
	free_thread(&monitor);
	return (free_all(&monitor));
}

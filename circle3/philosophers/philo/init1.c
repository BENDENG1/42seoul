/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:21 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:00:21 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_monitor *monitor)
{
	int	i;

	monitor->philo = malloc(sizeof(t_philo) * monitor->num_of_philo);
	if (monitor->philo == NULL)
		return (-1);
	i = -1;
	while (++i < monitor->num_of_philo)
	{
		monitor->philo[i].id = i;
		if (pthread_mutex_init(&(monitor->philo[i].m_last_eat), NULL) != 0)
			return (free_philo(monitor, i));
		if (pthread_mutex_init(&(monitor->philo[i].m_cnt_eat), NULL) != 0)
		{
			pthread_mutex_destroy(&(monitor->philo[i].m_last_eat));
			return (free_philo(monitor, i));
		}
		monitor->philo[i].last_eat = 0;
		monitor->philo[i].cnt_eat = 0;
		monitor->philo[i].first_fork = i;
		monitor->philo[i].second_fork = (i + 1) % monitor->num_of_philo;
		if (i % 2 == 1)
			swap_fork(&(monitor->philo[i]));
		monitor->philo[i].monitor = monitor;
	}
	return (0);
}

int	fork_init(t_monitor *monitor)
{
	int	i;

	monitor->fork = malloc(sizeof(int) * monitor->num_of_philo);
	if (monitor->fork == NULL)
	{
		free_philo(monitor, monitor->num_of_philo);
		return (-1);
	}
	i = 0;
	while (i < monitor->num_of_philo)
	{
		monitor->fork[i] = 0;
		i++;
	}
	return (0);
}

int	m_fork_init(t_monitor *monitor)
{
	int	i;

	monitor->m_fork = malloc(sizeof(pthread_mutex_t) * monitor->num_of_philo);
	if (monitor->m_fork == NULL)
	{
		free_philo(monitor, monitor->num_of_philo);
		free(monitor->fork);
		return (-1);
	}
	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (pthread_mutex_init(&(monitor->m_fork[i]), NULL) != 0)
		{
			free_philo(monitor, monitor->num_of_philo);
			free_fork(monitor, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	m_print_init(t_monitor *monitor)
{
	if (pthread_mutex_init(&(monitor->m_print), NULL) != 0)
	{
		free_philo(monitor, monitor->num_of_philo);
		free_fork(monitor, monitor->num_of_philo);
		return (-1);
	}
	return (0);
}

int	monitor_init(t_monitor *monitor, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (-1);
	monitor->num_of_philo = ft_atoi(argv[1]);
	monitor->time_to_die = ft_atoi(argv[2]);
	monitor->time_to_eat = ft_atoi(argv[3]);
	monitor->time_to_sleep = ft_atoi(argv[4]);
	monitor->must_eat_flag = 0;
	if (argc == 6)
	{
		monitor->must_eat_flag = 1;
		monitor->must_eat = ft_atoi(argv[5]);
	}
	monitor->finish_flag = 0;
	if (monitor->num_of_philo <= 0 || monitor->time_to_die <= 0 || \
		monitor->time_to_eat < 0 || monitor->time_to_sleep < 0)
		return (-1);
	if (philo_init(monitor) < 0 || fork_init(monitor) < 0 || \
		m_fork_init(monitor) < 0 || m_print_init(monitor) < 0)
		return (-1);
	return (0);
}

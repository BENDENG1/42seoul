/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:09 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:01:09 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_take_fork_one(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->first_fork] = 1;
	if (print_state(philo, "%ldms  %d  has taken a fork\n") < 0)
	{
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		return ;
	}
}

void	routine_take_fork_two(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			philo->monitor->fork[philo->first_fork] = 0;
			pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
			return ;
		}
		if (philo->monitor->fork[philo->second_fork] == 0)
		{
			philo->monitor->fork[philo->second_fork] = 1;
			pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
	}
	if (print_state(philo, "%ldms  %d  has taken a fork\n") < 0)
		routine_takeoff_fork(philo);
}

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	while (1)
	{
		routine_take_fork_one(philo);
		routine_take_fork_two(philo);
		routine_eat(philo);
		routine_takeoff_fork(philo);
		routine_sleep(philo);
		print_state(philo, "%ldms  %d  is thinking\n");
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		usleep(50);
	}
	return (0);
}

void	routine_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->first_fork] = 1;
	if (print_state(philo, "%ldms  %d  has taken a fork\n") < 0)
	{
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		return ;
	}
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
	philo->monitor->fork[philo->second_fork] = 1;
	if (print_state(philo, "%ldms  %d  has taken a fork\n") < 0)
	{
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		philo->monitor->fork[philo->second_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
		return ;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	if (philo->id % 2 == 1)
		usleep((double)philo->monitor->time_to_eat / 2 * 1000);
	while (1)
	{
		routine_take_fork(philo);
		routine_eat(philo);
		routine_takeoff_fork(philo);
		routine_sleep(philo);
		print_state(philo, "%ldms  %d  is thinking\n");
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		usleep(50);
	}
	return (0);
}

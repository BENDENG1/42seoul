/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:01:03 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:01:03 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = calc_time(&(philo->monitor->start_time), &curr_time);
	pthread_mutex_unlock(&(philo->m_last_eat));
	if (print_state(philo, "%ldms  %d  is eating\n") < 0)
	{
		routine_takeoff_fork(philo);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 200);
	pthread_mutex_lock(&(philo->m_cnt_eat));
	(philo->cnt_eat)++;
	pthread_mutex_unlock(&(philo->m_cnt_eat));
}

void	routine_sleep(t_philo *philo)
{
	struct timeval	start_time;

	if (print_state(philo, "%ldms  %d  is sleeping\n") < 0)
		return ;
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 200);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:20 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:01:20 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_error("Error: ft_atoi\n"));
		i++;
	}
	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > 1e11)
			break ;
		i++;
	}
	if (result > INT_MAX)
		return (ft_error("Error: ft_atoi\n"));
	return (result);
}

void	swap_fork(t_philo *philo)
{
	int	temp;

	temp = philo->first_fork;
	philo->first_fork = philo->second_fork;
	philo->second_fork = temp;
}

long	calc_time(struct timeval *start, struct timeval *end)
{
	long	diff;

	diff = (end->tv_sec - start->tv_sec) * 1e3 + \
			(end->tv_usec - start->tv_usec) / 1e3;
	return (diff);
}

void	routine_takeoff_fork(t_philo *philo)
{
	philo->monitor->fork[philo->first_fork] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->second_fork] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
	return ;
}

void	sleep_unit(t_monitor *monitor, long aim, \
						struct timeval start_time, long unit)
{
	struct timeval	cur;

	while (1)
	{
		if (gettimeofday(&(cur), NULL) != 0)
		{
			monitor->finish_flag = 2;
			return ;
		}
		if (calc_time(&(start_time), &cur) >= aim)
			break ;
		pthread_mutex_lock(&(monitor->m_finish));
		if (monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(monitor->m_finish));
			return ;
		}
		pthread_mutex_unlock(&(monitor->m_finish));
		usleep(unit);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:59:52 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 15:59:52 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_monitor *monitor)
{
	int				i;
	struct timeval	cur;
	long			gap;

	i = -1;
	while (++i < monitor->num_of_philo)
	{
		if (gettimeofday(&cur, NULL) != 0)
		{
			pthread_mutex_lock(&(monitor->m_finish));
			monitor->finish_flag = 2;
			pthread_mutex_unlock(&(monitor->m_finish));
			return (1);
		}
		pthread_mutex_lock(&(monitor->philo[i].m_last_eat));
		gap = calc_time(&(monitor->start_time), \
						&cur) - monitor->philo[i].last_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_last_eat));
		if (gap > monitor->time_to_die)
			return (print_finish(&(monitor->philo[i]), DIE));
	}
	return (0);
}

int	check_eat(t_monitor *monitor)
{
	int	i;
	int	cur;
	int	full;

	i = 0;
	full = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_mutex_lock(&(monitor->philo[i].m_cnt_eat));
		cur = monitor->philo[i].cnt_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_cnt_eat));
		if (cur >= monitor->must_eat)
			full++;
		i++;
	}
	if (full == monitor->num_of_philo)
		return (print_finish(&(monitor->philo[0]), FULL));
	return (0);
}

void	start_eat(t_monitor *monitor)
{
	while (1)
	{
		if (check_die(monitor))
			break ;
		if (monitor->must_eat_flag == 1)
		{
			if (check_eat(monitor))
				break ;
		}
	}
}

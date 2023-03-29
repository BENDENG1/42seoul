/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:30:37 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/28 19:34:16 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_monitor *monitor)
{
	if (pthread_mutex_init(&(monitor->m_start), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(monitor->m_finish), NULL) != 0)
	{
		pthread_mutex_destroy(&(monitor->m_start));
		return (-1);
	}
	return (0);
}

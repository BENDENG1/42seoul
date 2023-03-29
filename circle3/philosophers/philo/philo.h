/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:51 by gyroh             #+#    #+#             */
/*   Updated: 2023/03/24 16:00:51 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647
# define DIE 0
# define FULL 1

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		m_last_eat;
	long				last_eat;
	pthread_mutex_t		m_cnt_eat;
	int					cnt_eat;
	int					first_fork;
	int					second_fork;
	struct s_monitor	*monitor;
}	t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	m_start;
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	pthread_mutex_t	m_finish;
	int				finish_flag;
	struct timeval	start_time;
	pthread_t		*thread;
	t_philo			*philo;
	pthread_mutex_t	*m_fork;
	int				*fork;
	pthread_mutex_t	m_print;
}	t_monitor;

int		mutex_init(t_monitor *monitor);
int		create_philos(t_monitor *monitor);
int		ft_atoi(char *str);
void	swap_fork(t_philo *philo);
long	calc_time(struct timeval *start, struct timeval *end);
void	routine_takeoff_fork(t_philo *philo);
void	sleep_unit(t_monitor *monitor, long aim, \
					struct timeval start_time, long unit);
int		ft_error(char *msg);
int		print_state(t_philo *philo, char *msg);
int		print_finish(t_philo *philo, int status);
int		check_die(t_monitor *monitor);
int		check_eat(t_monitor *monitor);
void	start_eat(t_monitor *monitor);
int		free_philo(t_monitor *monitor, int philo_num);
void	free_fork(t_monitor *monitor, int philo_num);
void	free_thread(t_monitor *monitor);
int		free_all(t_monitor *monitor);
void	routine_take_fork_one(t_philo *philo);
void	routine_take_fork_two(t_philo *philo);
void	*routine_one(void *arg);
void	routine_take_fork(t_philo *philo);
void	*routine(void *arg);
int		philo_init(t_monitor *monitor);
int		fork_init(t_monitor *monitor);
int		m_fork_init(t_monitor *monitor);
int		m_print_init(t_monitor *monitor);
int		monitor_init(t_monitor *monitor, int argc, char **argv);
void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);

#endif

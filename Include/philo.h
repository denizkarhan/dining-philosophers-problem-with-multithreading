/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:25:09 by dkarhan           #+#    #+#             */
/*   Updated: 2022/07/28 19:17:49 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_common	t_common;

typedef struct phil
{
	struct s_common	*common;
	pthread_t		thread_id;
	int				pos;
	int				full;
	int				ate;
	char			thinking;
	long long		last_ate;
	long long		timestamp;
}t_phil;

typedef struct s_common
{
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	t_phil			*person;
	int				philosoph_count;
	int				dead_time;
	int				eat_time;
	int				sleep_time;
	int				eat_destination;
	int				eat_count;
	char			*states;
}t_common;

int		ft_atoi(const char *str);
long	get_timestamp(long timestamp);
void	control_args(int ac, char **av);
void	sleep_f(int how_long);
void	print_same(t_phil *ptr, char *str);

void	set_common(t_common *ptr, char **args);

void	*loop(void *phil);
void	take_fork(t_phil *ptr);
void	eating(t_phil	*ptr);
void	sleeping(t_phil *ptr);
void	thinking(t_phil *ptr);

#endif

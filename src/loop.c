/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:25:04 by dkarhan           #+#    #+#             */
/*   Updated: 2022/07/31 18:12:06 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

void	take_fork(t_phil *ptr)
{
	int		i;
	int		right;
	int		left;
	char	*states;

	if (ptr->common->philosoph_count < 2)
		return ;
	i = ptr->common->philosoph_count;
	right = (ptr->pos + 1) % i;
	left = (ptr->pos - 1 + i) % i;
	states = ptr->common->states;
	pthread_mutex_lock(&ptr->common->right_fork);
	if (!states[left] && !states[ptr->pos] && !states[right])
	{
		states[ptr->pos] = 1;
		print_same(ptr, "took the right fork 🥢");
		print_same(ptr, "took the left fork 🥢");
	}
	pthread_mutex_unlock(&ptr->common->right_fork);
}

void	*loop(void *phil)
{
	t_phil		*philo;

	philo = (t_phil *)phil;
	philo->last_ate = get_timestamp(0);
	while (1)
	{
		if (philo->pos % 2 != 0)
			usleep(2000);
		if (philo->common->eat_destination \
		&& philo->common->eat_count >= philo->common->philosoph_count)
		{
			pthread_mutex_lock(&philo->common->left_fork);
			printf("--- Ate the food at least %d times 👌 ---\n", \
			philo->common->eat_destination);
			exit(EXIT_SUCCESS);
		}
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	thinking(t_phil *philo)
{
	long long	timestamp;

	while (!philo->common->states[philo->pos])
	{
		take_fork(philo);
		if (!philo->common->states[philo->pos])
		{
			if (get_timestamp(philo->last_ate) >= philo->common->dead_time)
			{
				timestamp = get_timestamp(philo->timestamp);
				pthread_mutex_lock(&philo->common->left_fork);
				printf("Time: %lld | Philosoph Num: %d | died 💀\n", \
				timestamp, philo->pos + 1);
				exit(0);
			}
			sleep_f(1);
		}
		usleep(100);
	}
}

void	eating(t_phil	*philo)
{
	if (philo->common->states[philo->pos])
	{
		philo->last_ate = get_timestamp(0);
		print_same(philo, "is eating 🍝");
		sleep_f(philo->common->eat_time);
		if (philo->ate < philo->common->eat_destination)
			philo->ate++;
		if (!philo->full && philo->ate == philo->common->eat_destination)
		{
			philo->common->eat_count++;
			philo->full++;
		}
	}
}

void	sleeping(t_phil *philo)
{
	long long	t;

	if (philo->common->states[philo->pos])
	{
		print_same(philo, "is sleeping 💤");
		pthread_mutex_lock(&philo->common->right_fork);
		philo->common->states[philo->pos] = 0;
		pthread_mutex_unlock(&philo->common->right_fork);
		t = get_timestamp(0);
		while (get_timestamp(0) - t < philo->common->sleep_time)
		{
			if (get_timestamp(philo->last_ate) >= philo->common->dead_time)
			{
				pthread_mutex_lock(&philo->common->left_fork);
				printf("%ld %d died 💀\n", \
				get_timestamp(philo->timestamp), philo->pos);
				exit(EXIT_SUCCESS);
			}
			sleep_f(1);
		}
		print_same(philo, "is thinking 💭");
	}
}

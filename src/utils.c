/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:25:06 by dkarhan           #+#    #+#             */
/*   Updated: 2022/07/31 13:53:34 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && ++i)
		neg = -1;
	while (++i && str[i - 1] >= '0' && str[i - 1] <= '9')
		num = num * 10 + str[i - 1] - '0';
	return (num * neg);
}

void	control_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Wrong, Bad argument entering, \
		you must enter 4 or 5 arguments! 💥\n");
		exit(EXIT_FAILURE);
	}
	while (av[i])
	{
		if (ft_atoi(av[i++]) <= 0)
		{
			printf("Wrong, false number entering! 💥\n");
			exit(EXIT_FAILURE);
		}
	}
}

long	get_timestamp(long timestamp)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (!timestamp)
		return (now);
	else
		return (now - timestamp);
}

void	sleep_f(int how_long)
{
	long long	timestamp;

	timestamp = get_timestamp(0);
	while (get_timestamp(0) - timestamp < how_long)
		usleep(50);
}

void	print_same(t_phil *ptr, char *str)
{
	pthread_mutex_lock(&ptr->common->left_fork);
	printf("Time: %ld  | Phil_id: %d | %s\n", \
	get_timestamp(ptr->timestamp), ptr->pos + 1, str);
	pthread_mutex_unlock(&ptr->common->left_fork);
}

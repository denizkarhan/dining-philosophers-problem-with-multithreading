/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:25:02 by dkarhan           #+#    #+#             */
/*   Updated: 2022/07/31 13:44:06 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/philo.h"

int	program_end(t_common	*common)
{
	pthread_mutex_destroy(&common->right_fork);
	pthread_mutex_destroy(&common->left_fork);
	free(common->states);
	free(common->person);
	free(common->person->thread_id);
	free(common);
	return (0);
}

void	set_common(t_common *ptr, char **av)
{
	int	i;

	i = -1;
	ptr->philosoph_count = ft_atoi(av[1]);
	ptr->dead_time = ft_atoi(av[2]);
	ptr->eat_time = ft_atoi(av[3]);
	ptr->sleep_time = ft_atoi(av[4]);
	ptr->eat_count = 0;
	if (av[5] != NULL)
		ptr->eat_destination = ft_atoi(av[5]);
	ptr->person = malloc(sizeof(t_phil) * ptr->philosoph_count);
	ptr->states = malloc(ptr->philosoph_count);
	pthread_mutex_init(&ptr->right_fork, NULL);
	pthread_mutex_init(&ptr->left_fork, NULL);
	while (++i < ptr->philosoph_count)
	{
		ptr->states[i] = 0;
		ptr->person[i].thinking = 0;
		ptr->person[i].pos = i;
		ptr->person[i].common = ptr;
		ptr->person[i].ate = 0;
		ptr->person[i].full = 0;
		ptr->person[i].timestamp = get_timestamp(0);
	}
}

int	main(int ac, char **av)
{
	t_common	c;
	int			i;

	control_args(ac, av);
	set_common(&c, av);
	i = -1;
	while (++i < c.philosoph_count)
		pthread_create(&c.person[i].thread_id, NULL, &loop, &c.person[i]);
	i = -1;
	while (++i < c.philosoph_count)
		pthread_join(c.person[i].thread_id, NULL);
	return (program_end(&c));
}

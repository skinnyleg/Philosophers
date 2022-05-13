/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:29:38 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 20:32:02 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_shared	*shared_init(char **av)
{
	t_shared	*shared;

	shared = (t_shared *)malloc(sizeof(t_shared) * 1);
	if (shared == NULL)
		return (NULL);
	shared->philo_count = ft_atoi(av[1]);
	shared->philo_life = ft_atoi(av[2]) * 1000;
	shared->eating_time = ft_atoi(av[3]) * 1000;
	shared->sleep_time = ft_atoi(av[4]) * 1000;
	if (pthread_mutex_init(&(shared->death_flag), NULL) != 0)
		return (NULL);
	shared->index_death = -1;
	if (av[5])
		shared->max_eat = ft_atoi(av[5]);
	else
		shared->max_eat = -2;
	if (shared->philo_count == -1
		|| shared->sleep_time / 1000 == -1
		|| shared->max_eat == -1
		|| shared->philo_life / 1000 == -1
		|| shared->eating_time / 1000 == -1)
		return (NULL);
	shared->fork = fork_create(shared->philo_count);
	return (shared);
}

void	shared_destroy(t_shared *shared)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(shared->death_flag));
	while (i < shared->philo_count)
	{
		fork_destroy(shared->fork + i);
		i++;
	}
	free(shared->fork);
}

bool	shared_should_die(t_shared *shared, int last_meal, int index)
{
	pthread_mutex_lock(&(shared->death_flag));
	if (shared->index_death == -1
		&& ft_time(shared) - last_meal > shared->philo_life / 1000)
	{
		shared->index_death = index;
		shared->time_death = ft_time(shared);
		pthread_mutex_unlock(&(shared->death_flag));
		return (true);
	}
	pthread_mutex_unlock(&(shared->death_flag));
	return (false);
}

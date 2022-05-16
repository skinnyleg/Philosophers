/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:29:38 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/16 16:56:36 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

t_shared	*shared_init_bonus(char **av)
{
	t_shared	*shared;

	shared = (t_shared *)malloc(sizeof(t_shared) * 1);
	if (shared == NULL)
		return (NULL);
	shared->philo_count = ft_atoi_bonus(av[1]);
	shared->philo_life = ft_atoi_bonus(av[2]) * 1000;
	shared->eating_time = ft_atoi_bonus(av[3]) * 1000;
	shared->sleep_time = ft_atoi_bonus(av[4]) * 1000;
	if (av[5])
		shared->max_eat = ft_atoi_bonus(av[5]);
	else
		shared->max_eat = -2;
	shared->start_counter = ft_time_bonus();
	shared->last_meal = ft_time_bonus();
	if (shared->philo_count == -1
		|| shared->sleep_time / 1000 == -1
		|| shared->max_eat == -1
		|| shared->philo_life / 1000 == -1
		|| shared->eating_time / 1000 == -1)
		return (NULL);
	return (shared);
}

void	shared_destroy_bonus(t_shared *shared)
{
	free(shared->pid);
	free(shared);
}

void	shared_should_die_bonus(t_shared *shared)
{
	sem_wait(shared->check);
	if (ft_time_bonus() - shared->last_meal > shared->philo_life / 1000)
	{
		shared_destroy_bonus(shared);
		sem_post(shared->death);
	}
	sem_post(shared->check);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:45:37 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/16 17:25:30 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_routine_2_bonus(t_shared *shared)
{
	sem_post(shared->forks);
	sem_post(shared->forks);
	sem_wait(shared->death);
	printf("%ld %d is sleeping\n",
		ft_time_bonus() - shared->start_counter, shared->index + 1);
	sem_post(shared->death);
	increment_sleep_bonus(shared->sleep_time);
	sem_wait(shared->death);
	printf("%ld %d is thinking\n",
		ft_time_bonus() - shared->start_counter, shared->index + 1);
	sem_post(shared->death);

}

void	ft_routine_1_bonus(t_shared *shared)
{
	while (shared->max_eat == -2 || shared->max_eat--)
	{
		sem_wait(shared->forks);
		sem_wait(shared->death);
		printf("%ld %d has taken a fork\n",
			ft_time_bonus() - shared->start_counter, shared->index + 1);
		sem_post(shared->death);
		sem_wait(shared->forks);
		sem_wait(shared->death);
		printf("%ld %d has taken a fork\n",
			ft_time_bonus() - shared->start_counter, shared->index + 1);
		sem_post(shared->death);
		shared->last_meal = ft_time_bonus();
		sem_wait(shared->death);
		printf("%ld %d is eating\n",
			ft_time_bonus() - shared->start_counter, shared->index + 1);
		sem_post(shared->death);
		increment_sleep_bonus(shared->eating_time);
		ft_routine_2_bonus(shared);
	}
	shared_destroy_bonus(shared);
	exit(1);
}

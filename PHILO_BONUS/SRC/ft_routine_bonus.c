/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:45:37 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/15 21:27:27 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

bool	try_hold_bonus(t_shared *shared)
{
	while (1)
	{
		if (shared_should_die_bonus(shared) == true)
			return (false);
		if (try_hold_fork(fork) == true)
			return (true);
	}
	return (false);
}

int	ft_routine_2_bonus(t_shared *shared)
{
	sem_post(shared->forks);
	sem_post(shared->forks);
	printf("%ld %d is sleeping\n",
		ft_time() - shared->start_counter, shared->index + 1);
	if (increment_sleep(shared) == true)
		return (1);
	printf("%ld %d is thinking\n",
		ft_time() - shared->start_counter, shared->index + 1);
	return (0);
}

void	ft_routine_1_bonus(t_shared *shared)
{
	while (shared->max_eat == -2 || shared->max_eat--)
	{
		if (try_hold_(shared) == false)
			break ;
		printf("%ld %d has taken a fork\n",
			ft_time() - shared->start_counter, shared->index + 1);
		if (try_hold(shared) == false)
			break ;
		printf("%ld %d has taken a fork\n",
			ft_time() - shared->start_counter, shared->index + 1);
		shared->last_meal = ft_time();
		printf("%ld %d is eating\n",
			ft_time() - shared->start_counter, shared->index + 1);
		if (increment_sleep(shared) == true)
			break ;
		if (ft_routine_2_bonus(shared) == 1)
			break ;
	}
	return ;
}

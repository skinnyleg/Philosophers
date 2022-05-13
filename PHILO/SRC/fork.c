/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:38:42 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 21:02:58 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_fork	*fork_create(int forks)
{
	t_fork	*fork;
	int		i;

	i = 0;
	fork = (t_fork *)malloc(sizeof(t_fork) * forks);
	if (fork == NULL)
		return (NULL);
	while (i < forks)
	{
		if (fork_init(fork + i) == 1)
			return (free(fork), NULL);
		i++;
	}
	return (fork);
}

int	fork_init(t_fork *fork)
{
	if (pthread_mutex_init(&(fork->lock_hold), NULL) != 0)
		return (1);
	fork->hold = 0;
	return (0);
}

void	fork_destroy(t_fork *fork)
{
	pthread_mutex_destroy(&(fork->lock_hold));
}

bool	try_hold_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->lock_hold));
	if (fork->hold == 1)
	{
		pthread_mutex_unlock(&(fork->lock_hold));
		return (false);
	}
	fork->hold = 1;
	pthread_mutex_unlock(&(fork->lock_hold));
	return (true);
}

void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->lock_hold));
	fork->hold = 0;
	pthread_mutex_unlock(&(fork->lock_hold));
}

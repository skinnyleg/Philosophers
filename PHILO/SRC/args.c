/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:54:38 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 20:39:12 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_args	*args_create(int philo_count, char **av)
{
	t_args		*philo;
	t_shared	*shared;
	int			i;

	i = 0;
	shared = shared_init(av);
	if (shared == NULL)
		return (NULL);
	philo = (t_args *)malloc(sizeof(t_args) * philo_count);
	if (philo == NULL)
		return (NULL);
	gettimeofday(&(shared->start), NULL);
	while (i < philo_count)
	{
		philo[i].shared = shared;
		philo[i].index = i;
		philo[i].last_meal = ft_time(shared);
		i++;
	}
	args_init(philo);
	return (philo);
}

void	args_destroy(t_args *philo)
{
	if (philo->shared != NULL)
		shared_destroy(philo->shared);
}

void	args_init(t_args *philo)
{
	int	i;

	i = 0;
	while (i < philo->shared->philo_count)
	{
		ft_fork_left(philo + i, i);
		ft_fork_right(philo + i, i);
		i++;
	}
}

void	ft_fork_left(t_args *philo, int i)
{
	if (i % 2)
		philo->fork1 = &(philo->shared->fork[philo->index]);
	else
		philo->fork1 = &(philo->shared->fork[(philo->index
					+ philo->shared->philo_count - 1)
				% philo->shared->philo_count]);
}

void	ft_fork_right(t_args *philo, int i)
{
	if (i % 2)
		philo->fork2 = &(philo->shared->fork[(philo->index
					+ philo->shared->philo_count - 1)
				% philo->shared->philo_count]);
	else
		philo->fork2 = &(philo->shared->fork[philo->index]);
}

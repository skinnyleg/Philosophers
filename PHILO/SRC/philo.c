/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:08:06 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/14 15:33:34 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	try_hold(t_args *philo, t_fork *fork)
{
	while (1)
	{
		if (shared_should_die(philo->shared,
				philo->last_meal, philo->index) == true)
			return (false);
		if (try_hold_fork(fork) == true)
			return (true);
	}
	return (false);
}

int	ft_routine_2(t_args *philo)
{
	release_fork(philo->fork2);
	release_fork(philo->fork1);
	printf("%ld %d is sleeping\n",
		ft_time() - philo->shared->start_counter, philo->index + 1);
	if (increment_sleep(philo, philo->shared->sleep_time) == true)
		return (1);
	printf("%ld %d is thinking\n",
		ft_time() - philo->shared->start_counter, philo->index + 1);
	return (0);
}

void	*ft_routine_1(void *arg)
{
	t_args	*philo;

	philo = (t_args *)arg;
	if (philo->index % 2)
		usleep(200);
	while (philo->meals == -2 || philo->meals--)
	{
		if (try_hold(philo, philo->fork1) == false)
			return (NULL);
		printf("%ld %d has taken a fork\n",
			ft_time() - philo->shared->start_counter, philo->index + 1);
		if (try_hold(philo, philo->fork2) == false)
			return (NULL);
		printf("%ld %d has taken a fork\n",
			ft_time() - philo->shared->start_counter, philo->index + 1);
		philo->last_meal = ft_time();
		printf("%ld %d is eating\n",
			ft_time() - philo->shared->start_counter, philo->index + 1);
		if (increment_sleep(philo, philo->shared->eating_time) == true)
			return (NULL);
		if (ft_routine_2(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	ft_threads(t_args *philo)
{
	pthread_t	*th;
	int			i;

	i = 0;
	th = (pthread_t *)malloc(sizeof(pthread_t) * philo->shared->philo_count);
	if (th == NULL)
		return (1);
	while (i < philo->shared->philo_count)
	{
		if (pthread_create(th + i, NULL, ft_routine_1, philo + i) != 0)
			return (printf("thread creation error\n"), free(th), 1);
		i++;
	}
	i = 0;
	while (i < philo->shared->philo_count)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("thread joining error\n"), free(th), 1);
		i++;
	}
	if (philo->shared->index_death != -1)
		printf("%ld %d died\n",
			philo->shared->time_death, philo->shared->index_death + 1);
	free(th);
	return (0);
}

int	main(int ac, char **av)
{
	t_args	*philo;
	int		i;

	if (ac < 5 || ac > 6)
		return (printf("arguments error\n"), 1);
	if (ft_checknumbers(av) == 1)
		return (1);
	i = ft_atoi(av[1]);
	philo = args_create(i, av);
	if (philo == NULL)
		return (destroy_all_err(philo), 1);
	if (ft_threads(philo) == 1)
		return (destroy_all_err(philo), 1);
	destroy_all(philo);
	return (0);
}

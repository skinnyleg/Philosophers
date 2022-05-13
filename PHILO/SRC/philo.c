/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:08:06 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 21:04:44 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *arg)
{
	t_args	*philo;

	philo = (t_args *)arg;
	if (try_hold_fork(philo->fork1) == false)
		return (NULL);
	if (try_hold_fork(philo->fork2) == false)
		return (NULL);
	printf("%d %d has taken a fork\n", ft_time(philo->shared), philo->index + 1);
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
		philo[i].index = i;
		if (pthread_create(th + i, NULL, ft_routine, philo + i) != 0)
			return (printf("thread creation error\n"), 1);
		i++;
	}
	i = 0;
	while (i < philo->shared->philo_count)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (printf("thread joining error\n"), 1);
		i++;
	}
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
}

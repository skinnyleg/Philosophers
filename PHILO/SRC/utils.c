/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:33 by haitam            #+#    #+#             */
/*   Updated: 2022/05/14 15:31:45 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

void	ft_error_num(char **num)
{
	printf("Error\n");
	ft_free_all(num);
}

int	ft_malloc(void *tab)
{
	if (tab == NULL)
	{
		printf("malloc error\n");
		return (1);
	}
	return (0);
}

long	ft_time(void)
{
	long			time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000 + end.tv_usec / 1000);
	return (time);
}

bool	increment_sleep(t_args *philo, int duration)
{
	long			start;

	start = ft_time();
	while (ft_time() - start < duration / 1000)
	{
		if (shared_should_die(philo->shared,
				philo->last_meal, philo->index) == true)
			return (true);
		usleep(100);
	}
	return (false);
}

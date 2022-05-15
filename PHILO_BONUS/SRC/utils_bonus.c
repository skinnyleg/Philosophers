/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:33 by haitam            #+#    #+#             */
/*   Updated: 2022/05/15 19:14:30 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_isdigit_bonus(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

void	ft_error_num_bonus(char **num)
{
	printf("Error\n");
	ft_free_all_bonus(num);
}

int	ft_malloc_bonus(void *tab)
{
	if (tab == NULL)
	{
		printf("malloc error\n");
		return (1);
	}
	return (0);
}

long	ft_time_bonus(void)
{
	long			time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000 + end.tv_usec / 1000);
	return (time);
}

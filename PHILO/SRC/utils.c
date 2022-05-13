/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:55:33 by haitam            #+#    #+#             */
/*   Updated: 2022/05/13 20:51:49 by hmoubal          ###   ########.fr       */
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

int	ft_time(t_shared	*shared)
{
	int				time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000 + end.tv_usec / 1000)
		- (shared->start.tv_sec * 1000 + shared->start.tv_usec / 1000);
	return (time);
}

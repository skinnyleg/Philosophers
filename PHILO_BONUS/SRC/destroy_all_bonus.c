/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:34:11 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/16 17:26:21 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	destroy_all_err_bonus(t_shared *shared)
{
	// sem_close(shared->check);
	sem_close(shared->forks);
	sem_close(shared->death);
	shared_destroy_bonus(shared);
	printf("ERROR\n");
}

void	destroy_all_bonus(t_shared *shared)
{
	// sem_close(shared->check);
	sem_close(shared->forks);
	sem_close(shared->death);
	shared_destroy_bonus(shared);
}

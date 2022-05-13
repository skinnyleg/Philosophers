/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:34:11 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 20:29:53 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_all_err(t_args *philo)
{
	if (philo != NULL)
		args_destroy(philo);
	free(philo);
	printf("ERROR\n");
}

void	destroy_all(t_args *philo)
{
	args_destroy(philo);
	free(philo);
}

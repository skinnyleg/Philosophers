/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:34:11 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/15 20:36:21 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	destroy_all_err_bonus(t_shared *shared)
{
	shared_destroy_bonus(shared);
	printf("ERROR\n");
}

void	destroy_all_bonus(t_shared *shared)
{
	shared_destroy_bonus(shared);
}

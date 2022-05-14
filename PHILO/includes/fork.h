/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:39:31 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/14 14:53:13 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include "philo.h"
# include <pthread.h>

typedef struct s_fork{
	int				hold;
	pthread_mutex_t	lock_hold;
}	t_fork;

t_fork	*fork_create(int forks);
int		fork_init(t_fork *fork);
bool	try_hold_fork(t_fork *fork);
void	release_fork(t_fork *fork);
void	fork_destroy(t_fork *fork);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:42:34 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/16 16:39:52 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_BONUS_H
# define SHARED_BONUS_H

# include "philo_bonus.h"

# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_shared{
	int				philo_count;
	int				philo_life;
	int				max_eat;
	int				sleep_time;
	int				eating_time;
	long			start_counter;
	long			last_meal;
	int				index;
	pid_t			*pid;
	sem_t			*death;
	sem_t			*check;
	sem_t			*output;
	sem_t			*forks;
}	t_shared;

t_shared	*shared_init_bonus(char **av);
void		shared_destroy_bonus(t_shared *shared);
void		shared_should_die_bonus(t_shared *shared);
#endif

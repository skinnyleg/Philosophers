/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:42:34 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/14 15:12:41 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "philo.h"
# include "fork.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_shared{
	int				philo_count;
	int				philo_life;
	int				max_eat;
	int				sleep_time;
	int				eating_time;
	int				index_death;
	long			time_death;
	long			start_counter;
	struct timeval	start;
	pthread_mutex_t	death_flag;
	t_fork			*fork;
}	t_shared;

t_shared	*shared_init(char **av);
void		shared_destroy(t_shared *shared);
bool		shared_should_die(t_shared *shared, long last_meal, int index);

#endif

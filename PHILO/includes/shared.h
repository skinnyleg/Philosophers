/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:42:34 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/13 21:22:44 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "philo.h"

typedef struct s_shared{
	int				philo_count;
	int				philo_life;
	int				max_eat;
	int				sleep_time;
	int				eating_time;
	int				index_death;
	long			time_death;
	struct timeval	start;
	pthread_mutex_t	death_flag;
	t_fork			*fork;
}	t_shared;

t_shared	*shared_init(char **av);
void		shared_destroy(t_shared *shared);
bool		shared_should_die(t_shared *shared, int last_meal, int index);

#endif

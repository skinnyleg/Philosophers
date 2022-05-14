/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:52:34 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/14 14:54:18 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "philo.h"
# include "fork.h"
# include "shared.h"

typedef struct s_args{
	t_fork		*fork1;
	t_fork		*fork2;
	int			index;
	int			meals;
	long		last_meal;
	t_shared	*shared;
}	t_args;

t_args	*args_create(int philo_count, char **av);
void	args_init(t_args *philo);
void	args_destroy(t_args *philo);
void	ft_fork_left(t_args *philo, int i);
void	ft_fork_right(t_args *philo, int i);
#endif

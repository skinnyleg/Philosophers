/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:09:05 by haitam            #+#    #+#             */
/*   Updated: 2022/05/16 17:08:00 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
#include <signal.h>
# include <stdbool.h>
# include <semaphore.h>
# include "shared_bonus.h"
# include "destroy_all_bonus.h"

typedef struct s_int{
	int	i;
	int	j;
	int	k;
}	t_int;

int		ft_atoi_bonus(const	char *str);
void	ft_error_bonus(void);
int		ft_checknumbers_bonus(char **av);
void	ft_free_all_bonus(char **str);
int		ft_count_bonus(char **str, int k, int j);
int		ft_cont_bonus(char **num, int k, int j);
int		ft_over_bonus(char **num);
void	ft_error_num_bonus(char **num);
char	**ft_split_bonus(char const *s,	char c);
void	*ft_memcpy_bonus(void *dest, const void *src, size_t size);
int		ft_malloc_bonus(void *tab);
int		ft_isdigit_bonus(int a);
long	ft_time_bonus(void);
void	ft_routine_1_bonus(t_shared *shared);
void	ft_routine_2_bonus(t_shared *shared);
bool	try_hold_bonus(t_shared *shared);
void	increment_sleep_bonus(int duration);
#endif

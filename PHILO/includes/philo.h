/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:09:05 by haitam            #+#    #+#             */
/*   Updated: 2022/05/13 17:50:31 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include "fork.h"
# include "shared.h"
# include "args.h"
# include "destroy_all.h"

typedef struct s_int{
	int	i;
	int	j;
	int	k;
}	t_int;

int		ft_atoi(const	char	*str);
void	ft_error(void);
int		ft_checknumbers(char **av);
void	ft_free_all(char **str);
int		ft_count(char **str, int k, int j);
int		ft_cont(char **num, int k, int j);
int		ft_over(char **num);
void	ft_error_num(char **num);
char	**ft_split(char const *s,	char c);
void	*ft_memcpy(void *dest,	const void *src,	size_t size);
int		ft_malloc(void *tab);
int		ft_isdigit(int a);
int		ft_time(t_shared *shared);
#endif

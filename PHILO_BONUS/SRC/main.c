/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:58 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/15 21:30:07 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

void	*check_death(void *arg)
{
	t_shared *const	shared = arg;
	while(1)
	{
		sem_wait(shared->death);
		exit(1);
	}
}

void	ft_start(t_shared *shared, int i)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, check_death, shared) != 0)
	{
		printf("thread creation error\n");
		exit(1);
	}
	pthread_detach(th);
	shared->index = i;
	ft_routine_1_bonus(shared);
}

int	ft_proc(t_shared *shared)
{
	int		i;

	i = 0;
	shared->pid = (pid_t *)malloc(sizeof(pid_t) * shared->philo_count);
	if (shared->pid == NULL)
		return (1);
	while (i < shared->philo_count)
	{
		shared->pid[i] = fork();
		if (shared->pid[i] == 0)
			ft_start(shared, i);
		i++;
	}
	while (1)
	{
		printf("waiting .. ..\n");
		waitpid(-1, &i, 0);
		printf("all done\n");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_shared	*shared;

	if (ac < 5 || ac > 6)
		return (printf("arguments error\n"), 1);
	if (ft_checknumbers_bonus(av) == 1)
		return (1);
	sem_unlink("death");
	sem_unlink("forks");
	shared = shared_init_bonus(av);
	shared->death = sem_open("death", O_CREAT, 0645, 0);
	shared->death = sem_open("forks", O_CREAT, 0645, shared->philo_count);
	if (ft_proc(shared) == 1)
		return (destroy_all_err_bonus(shared), 1);
	destroy_all_bonus(shared);
}

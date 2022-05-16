/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:58 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/16 17:31:42 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

void	*check_death(void *arg)
{
	t_shared *const	shared = arg;
	while(1)
	{
		sem_wait(shared->death);
		// sem_wait(shared->check);
		if (ft_time_bonus() - shared->last_meal > shared->philo_life / 1000)
		{
			printf("%ld %d died\n", ft_time_bonus() - shared->start_counter, shared->index + 1);
			shared_destroy_bonus(shared);
			exit(1);
		}
		// sem_post(shared->check);
		sem_post(shared->death);
	}
}

void	ft_start(t_shared *shared, int i)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, check_death, shared) != 0)
	{
		printf("thread creation error\n");
		shared_destroy_bonus(shared);
		exit(1);
	}
	shared->index = i;
	ft_routine_1_bonus(shared);
}

int	ft_proc(t_shared *shared)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	while (waitpid(-1, &i, 0) > 0)
	{
		if (WIFEXITED(i) && WEXITSTATUS(i) == 1)
		{
			while (j < shared->philo_count)
			{
				kill(shared->pid[j],SIGTERM);
				j++;
			}
		}
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
	// sem_unlink("check");
	// sem_unlink("output");
	shared = shared_init_bonus(av);
	shared->death = sem_open("death", O_CREAT, 0645, 1);
	shared->forks = sem_open("forks", O_CREAT, 0645, shared->philo_count);
	// shared->check = sem_open("check", O_CREAT, 0645, 1);
	// shared->output = sem_open("output", O_CREAT, 0645, 1);
	if (ft_proc(shared) == 1)
		return (destroy_all_err_bonus(shared), 1);
	destroy_all_bonus(shared);
}

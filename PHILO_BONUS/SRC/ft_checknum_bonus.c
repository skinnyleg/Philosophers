/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknum_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:42:30 by haitam            #+#    #+#             */
/*   Updated: 2022/05/15 19:16:01 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_over_bonus(char **num)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	j = 0;
	n = 0;
	while (num[++i])
	{
		while (num[i][j] != '\0')
		{
			if (num[i][j] == '-' || num[i][j] == '+')
				j++;
			while (num[i][j] == '0')
				j++;
			while (num[i][j])
			{
				j++;
				n++;
			}
			if (n > 10)
				return (ft_error_num_bonus(num), 1);
		}
	}
	return (0);
}

int	ft_cont_bonus(char **num, int k, int j)
{
	while (num[k])
	{
		j = ft_count_bonus(num, k, j);
		while (num[k][j])
		{
			if (ft_isdigit_bonus(num[k][j]) == 0)
				return (ft_error_num_bonus(num), 1);
			j++;
		}
		k++;
	}
	return (0);
}

int	ft_count_bonus(char **str, int k, int j)
{
	while ((str[k][j] >= 9 && str[k][j] <= 13) || str[k][j] == 32)
		j++;
	if (str[k][j] == '-' || str[k][j] == '+')
		j++;
	return (j);
}

void	ft_free_all_bonus(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_checknumbers_bonus(char **av)
{
	t_int	var;
	char	**num;

	var.i = 1;
	num = NULL;
	var.j = 0;
	while (av[var.i])
	{
		var.k = 0;
		num = ft_split_bonus(av[var.i], 32);
		if (ft_malloc_bonus(num) == 1)
			return (1);
		if (ft_over_bonus(num) == 1)
			return (1);
		if (num[var.k] == NULL)
			return (ft_error_num_bonus(num), 1);
		if (ft_cont_bonus(num, var.k, var.j) == 1)
			return (1);
		ft_free_all_bonus(num);
		(var.i)++;
	}
	return (0);
}

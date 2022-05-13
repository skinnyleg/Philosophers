/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:42:30 by haitam            #+#    #+#             */
/*   Updated: 2022/05/13 20:54:55 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_over(char **num)
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
				return (ft_error_num(num), 1);
		}
	}
	return (0);
}

int	ft_cont(char **num, int k, int j)
{
	while (num[k])
	{
		j = ft_count(num, k, j);
		while (num[k][j])
		{
			if (ft_isdigit(num[k][j]) == 0)
				return (ft_error_num(num), 1);
			j++;
		}
		k++;
	}
	return (0);
}

int	ft_count(char **str, int k, int j)
{
	while ((str[k][j] >= 9 && str[k][j] <= 13) || str[k][j] == 32)
		j++;
	if (str[k][j] == '-' || str[k][j] == '+')
		j++;
	return (j);
}

void	ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_checknumbers(char **av)
{
	t_int	var;
	char	**num;

	var.i = 1;
	num = NULL;
	var.j = 0;
	while (av[var.i])
	{
		var.k = 0;
		num = ft_split(av[var.i], 32);
		if (ft_malloc(num) == 1)
			return (1);
		if (ft_over(num) == 1)
			return (1);
		if (num[var.k] == NULL)
			return (ft_error_num(num), 1);
		if (ft_cont(num, var.k, var.j) == 1)
			return (1);
		ft_free_all(num);
		(var.i)++;
	}
	return (0);
}

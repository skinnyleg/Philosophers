/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:07:58 by hmoubal           #+#    #+#             */
/*   Updated: 2022/05/15 19:15:27 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("arguments error\n"), 1);
	if (ft_checknumbers_bonus(av) == 1)
		return (1);
}

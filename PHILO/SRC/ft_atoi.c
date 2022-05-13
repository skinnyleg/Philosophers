/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:33:37 by haitam            #+#    #+#             */
/*   Updated: 2022/05/13 15:36:39 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_memcpy(void *dest,	const void *src,	size_t size)
{
	char	*p1;
	char	*p2;
	int		i;

	p1 = dest;
	p2 = (char *)src;
	if (!p1 && !p2)
		return (NULL);
	i = 0;
	while (size != 0)
	{
		p1[i] = p2[i];
		i++;
		size--;
	}
	return (dest);
}

int	ft_atoi(const	char	*str)
{
	int		i;
	int		sign;
	long	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if ((r * sign) > 2147483647 || (r * sign) < 0)
		return (-1);
	return (sign * r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:49:29 by haitam            #+#    #+#             */
/*   Updated: 2022/05/15 19:18:26 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	calc_block_bonus(char const *str,	char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!str[i] || str[0] == c)
		j = 0;
	while (str[i] != '\0')
		if (str[i++] == c && str[i] != c && str[i] != '\0')
			j++;
	return (j);
}

static char	*free_memory_bonus(char **s,	int block)
{
	while (block--)
		free(s[block]);
	return (NULL);
}

static char	**calc_size_copy_bonus(char **hub,	char *str,	char c,	int block)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (*str != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (i != 0 && l < block)
		{
			hub[l] = (char *)malloc((i + 1) * sizeof(char));
			if (hub[l] == NULL)
				free_memory_bonus(hub, block);
			ft_memcpy_bonus(hub[l], str, i);
			hub[l][i] = '\0';
			l++;
			str = str + i;
			i = 0;
		}
		else
			str = str + 1;
	}
	hub[l] = NULL;
	return (hub);
}

char	**ft_split_bonus(char const *s,	char c)
{
	int		j;
	char	**hub;

	j = 0;
	hub = NULL;
	if (!s)
		return (NULL);
	j = calc_block_bonus(s, c);
	hub = (char **)malloc((j + 1) * sizeof(char *));
	if (hub == NULL)
		return (NULL);
	calc_size_copy_bonus(hub, (char *)s, c, j);
	return (hub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truedeveloper <truedeveloper@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:33:15 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/20 19:18:39 by truedevelop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_space(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && ft_isspace(s[i]))
	{
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_isnum(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	assign_num(t_stack **a, int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	if (!(*a) || !av || ac < 1)
		return (0);
	i = 1;
	k = 0;
	while (i < ac)
	{
		s = ft_split(av[i], ' ');
		j = 0;
		while (j < count_split(s))
		{
			if (ft_atoi(s[j]) < INT_MIN || ft_atoi(s[j]) > INT_MAX)
				return (free_split(s), 0);
			(*a)->s[k] = ft_atoi(s[j]);
			j++;
			k++;
		}
		free_split(s);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:43:00 by truedevelop       #+#    #+#             */
/*   Updated: 2024/08/31 15:03:32 by h                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_split(char **argv)
{
	int	count;

	if (!argv)
		return (0);
	count = 0;
	while (argv[count])
		count++;
	return (count);
}

int	intialize_stack_arg(t_stack **a, t_stack **b, char **split)
{
	int		i;
	long	temp;

	(*a) = (t_stack *)malloc(sizeof(t_stack));
	(*b) = (t_stack *)malloc(sizeof(t_stack));
	if (!*a || !*b)
		return (0);
	(*b)->s = (int *)malloc(sizeof(int) * (count_split(split)));
	(*a)->s = (int *)malloc(sizeof(int) * (count_split(split)));
	if (!(*a)->s || !(*b)->s)
		return (0);
	(*a)->sz = (count_split(split));
	(*b)->sz = (count_split(split));
	(*b)->t = (count_split(split));
	i = 0;
	temp = 0;
	while (i < count_split(split))
	{
		temp = ft_atoi(split[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (0);
		(*a)->s[i] = temp;
		i++;
	}
	return ((*a)->t = 0, 1);
}

int	check_arg_input(int argc, char **s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = count_split(s);
	while (i < count)
	{
		j = 0;
		if (s[i][j] == '\0')
			return (0);
		while (s[i][j] != '\0')
		{
			if ((s[i][j] == '-' || s[i][j] == '+') && ft_isdigit(s[i][j
					+ 1]) || (s[i][j] >= 9 && s[i][j] <= 13))
				j++;
			if (!ft_isdigit(s[i][j]) || !check_space(s[1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	one_arg_isunique(int count, char **s)
{
	int	i;
	int	j;

	if (count <= 0 || !s)
		return (0);
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '\0')
			return (0);
		while (s[i][j] == ' ')
		{
			if (s[i][j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

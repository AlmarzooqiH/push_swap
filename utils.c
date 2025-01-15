/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:48:42 by truedevelop       #+#    #+#             */
/*   Updated: 2024/08/31 15:03:06 by h                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				src: https://www.asciiart.eu/text-to-ascii-art
					____  _   _ ____  _   _     ______        ___    ____
				|  _ \| | | / ___|| | | |   / ___\ \      / / \  |  _ \
				| |_) | | | \___ \| |_| |   \___ \\ \ /\ / / _ \ | |_) |
				|  __/| |_| |___) |  _  |    ___) |\ V  V / ___ \|  __/
				|_|    \___/|____/|_| |_|___|____/  \_/\_/_/   \_\_|
										|_____|

*/

#include "push_swap.h"

int	check_input(int ac, char **av)
{
	int		i;
	int		j;
	char	**s;

	if (!av || !av[1])
		return (0);
	i = 1;
	while (av[i])
	{
		if (!check_space(av[i]))
			return (0);
		s = ft_split(av[i++], ' ');
		if (!s)
			return (0);
		j = 0;
		while (s[j])
		{
			if (!check_space(s[j]) || !check_isnum(s[j]))
				return (0);
			j++;
		}
		free_split(s);
	}
	return (1);
}

int	is_unique(t_stack **a)
{
	int	i;
	int	j;

	if (!(*a))
		return (0);
	i = (*a)->t;
	while (i < (*a)->sz)
	{
		j = i + 1;
		while (j < (*a)->sz)
		{
			if ((*a)->s[i] == (*a)->s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
	@brief				Will check if the stack is
						sorted in acending or decidng order.
	@param	stk			The stack you want to check.
	@param	compare:	0 in Acending order and 1 in Decending order.
	@return				1 if the stack is sorted in
						acending/decending order, 0 otherwise.
*/
int	is_sorted(t_stack **stk, int compare)
{
	int	i;

	if (!stk || !(*stk) || !((*stk)->s))
		return (0);
	if ((*stk)->sz == 1)
		return (1);
	i = (*stk)->t;
	while (i < (*stk)->sz)
	{
		if (i + 1 >= (*stk)->sz)
			break ;
		if (compare == 0 && (*stk)->s[i] > (*stk)->s[i + 1])
			return (0);
		if (compare == 1 && (*stk)->s[i] < (*stk)->s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_empty(t_stack **stk)
{
	return ((*stk)->t == (*stk)->sz);
}

void	fs(t_stack **a, t_stack **b)
{
	if ((*a))
	{
		ft_bzero((*a)->s, (*a)->sz);
		free((*a)->s);
		(*a)->sz = 0;
		(*a)->t = 0;
		free((*a));
	}
	if ((*b))
	{
		free((*b)->s);
		(*b)->t = 0;
		(*b)->sz = 0;
		free((*b));
	}
}

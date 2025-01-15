/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truedeveloper <truedeveloper@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:55:09 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/10 14:27:12 by truedevelop      ###   ########.fr       */
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

int	sa(t_stack **a, int from)
{
	int	temp;

	if (!(*a))
		return (0);
	if (is_empty(a) || (*a)->t + 1 == (*a)->sz)
		return (1);
	temp = (*a)->s[(*a)->t];
	(*a)->s[(*a)->t] = (*a)->s[(*a)->t + 1];
	(*a)->s[(*a)->t + 1] = temp;
	if (from == 0)
		ft_printf("sa\n");
	else if (from == 1)
		ft_printf("sb\n");
	return (1);
}

int	sb(t_stack **b, int from)
{
	return (sa(b, from));
}

int	ss(t_stack **a, t_stack **b, int from)
{
	if (from == 2)
	{
		sa(a, 3);
		sb(b, 3);
		ft_printf("ss\n");
	}
	return (1);
}

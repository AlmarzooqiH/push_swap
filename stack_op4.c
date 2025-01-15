/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:57:04 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/17 14:50:31 by hamalmar         ###   ########.fr       */
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

int	rra(t_stack **a, int from)
{
	int	i;
	int	temp;

	if (!(*a))
		return (0);
	if (is_empty(a) || (*a)->t + 1 >= (*a)->sz)
		return (1);
	i = (*a)->sz - 1;
	temp = (*a)->s[(*a)->sz - 1];
	while (i > (*a)->t)
	{
		(*a)->s[i] = (*a)->s[i - 1];
		i--;
	}
	(*a)->s[i] = temp;
	if (from == 0)
		ft_printf("rra\n");
	else if (from == 1)
		ft_printf("rrb\n");
	else if (from == 2)
		ft_printf("rrr\n");
	return (1);
}

int	rrb(t_stack **b, int from)
{
	return (rra(b, from));
}

int	rrr(t_stack **a, t_stack **b, int from)
{
	if (from == 2)
	{
		rra(a, 3);
		rrb(b, 3);
		ft_printf("rrr\n");
	}
	return (1);
}

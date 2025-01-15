/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:29:58 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/31 14:52:51 by h                ###   ########.fr       */
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

int	ra(t_stack **a, int from)
{
	int	i;
	int	temp;

	if (!(*a))
		return (0);
	if ((*a)->t + 1 == (*a)->sz)
		return (1);
	i = (*a)->t;
	temp = (*a)->s[(*a)->t];
	while (i < (*a)->sz)
	{
		if (i + 1 == (*a)->sz)
			break ;
		(*a)->s[i] = (*a)->s[i + 1];
		i++;
	}
	i++;
	(*a)->s[i - 1] = temp;
	if (from == 0)
		ft_printf("ra\n");
	else if (from == 1)
		ft_printf("rb\n");
	return (1);
}

int	rb(t_stack **b, int from)
{
	return (ra(b, from));
}

int	rr(t_stack **a, t_stack **b, int from)
{
	if (from == 2)
	{
		ra(a, from);
		rb(b, from);
		ft_printf("rr\n");
	}
	return (1);
}

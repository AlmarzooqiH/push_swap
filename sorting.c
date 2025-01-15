/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:29:00 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/31 13:49:29 by hamalmar         ###   ########.fr       */
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

int	hamad_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	mb;
	int	shift;

	if (!(*a) || !(*b))
		return (0);
	asi(a);
	mb = gmb(a);
	shift = 0;
	while (shift < mb)
	{
		i = 0;
		while (i < (*a)->sz)
		{
			if (((*a)->s[(*a)->t] >> shift) & 1)
				ra(a, 0);
			else
				pb(a, b, 1);
			i++;
		}
		shift++;
		while (!is_empty(b))
			pa(a, b, 0);
	}
	return (1);
}

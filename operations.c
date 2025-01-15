/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyte <hbyte@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:36:31 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/15 23:42:51 by hbyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dos(t_stack **a, t_stack **b, int from)
{
	int	ise;

	if (!(*a) || !(*b))
		return (0);
	ise = is_empty(b);
	if ((*a)->s[(*a)->t] > (*a)->s[(*a)->t + 1] && !ise
		&& (*b)->s[(*b)->t] < (*b)->s[(*b)->t + 1])
	{
		if (from == 1)
			return (ss(a, b, 2), 1);
		else if (from == 2)
			return (ss(a, b, 2), hamad_sort_a(a, b));
	}
	if (from == 1 && (*a)->s[(*a)->t] > (*a)->s[(*a)->t + 1])
		return (sa(a, 0), hamad_sort_b(a, b));
	if (from == 2 && !ise && (*b)->s[(*b)->t] < (*b)->s[(*b)->t + 1])
		return (sb(a, 0), hamad_sort_a(a, b));
	if (from == 1)
		return (hamad_sort_a(a, b));
	return (hamad_sort_b(a, b));
}

// mi  < (((*a)->sz - (*a)->t) * 50) / 100  &&
int	dop(t_stack **a, t_stack **b, int from)
{
	int	mia;
	int	mib;
	int	ise;

	if (!(*a) || !(*b))
		return (0);
	mia = gmi(a, 0);
	ise = is_empty(b);
	if (!ise)
		mib = gmi(b, 1);
	if (from == 1 && (*a)->s[(*a)->t] < (*a)->s[(*a)->sz - 1])
		return (pb(a, b, 1), hamad_sort_b(a, b));
	if (from == 2 && !ise && mib == (*b)->t && is_sorted(a, 0))
		return (pa(a, b, 0), hamad_sort_a(a, b));
	if (from == 1)
		return (hamad_sort_a(a, b));
	return (hamad_sort_b(a, b));
}

int	dor(t_stack **a, t_stack **b, int from)
{
	int	mia;
	int	mib;
	int	ise;

	if (!(*a) || !(*b))
		return (0);
	mia = gmi(a, 0);
	ise = is_empty(b);
	if (!ise)
		mib = gmi(b, 1);
	if (!ise && mib <= (((*b)->sz - 1) / 2) && mia <= (((*b)->sz - 1) / 2))
	{
		if (from == 1)
			return (rr(a, b, 2), hamad_sort_b(a, b));
		else if (from == 2)
			return (rr(a, b, 2), hamad_sort_a(a, b));
	}
	if (from == 1 && (*a)->s[(*a)->t] > (*a)->s[(*a)->sz - 1]
		&& mia <= ((*a)->sz - 1) / 2)
		return (ra(a, 0), hamad_sort_b(a, b));
	if (!ise && mib <= (((*b)->sz - 1) / 2))
		return (rb(a, 1), hamad_sort_a(a, b));
	if (from == 1)
		return (hamad_sort_a(a, b));
	return (hamad_sort_b(a, b));
}

int	dorr(t_stack **a, t_stack **b, int from)
{
	int	mia;
	int	mib;
	int	ise;

	if (!(*a) || !(*b))
		return (0);
	mia = gmi(a, 0);
	ise = is_empty(b);
	if (!ise)
		mib = gmi(b, 1);
	if (!ise && mib > (((*b)->sz - 1) / 2) && mia > ((*a)->sz - 1) / 2)
	{
		if (from == 1)
			return (rrr(a, b, 2), hamad_sort_b(a, b));
		else if (from == 2)
			return (rrr(a, b, 2), hamad_sort_a(a, b));
	}
	if (from == 1 && mia > ((*a)->sz - 1) / 2)
		return (rra(a, 0), hamad_sort_b(a, b));
	if (from == 2 && !ise && mib > (((*b)->sz - 1) / 2))
		return (rrb(a, 0), hamad_sort_b(a, b));
	if (from == 1)
		return (hamad_sort_a(a, b));
	return (hamad_sort_b(a, b));
}

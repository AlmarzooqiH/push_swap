/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:17:19 by truedevelop       #+#    #+#             */
/*   Updated: 2024/08/31 15:04:29 by h                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	@breif	Get Min/Max Index this function will get hte mininum/maxiumum
	element in the stack.
	@param	stk		Stack we want to find the min/max element index
	@param 	compare	0 for miniumum element, 1 for maximum element.
	@var	i		Where we will start comparing ((*stk)->t)
	@var	index	The index of the min/max element in the stack
	@return			Will return the min/max index in the stack
*/
int	gmi(t_stack **stk, int compare)
{
	int	i;
	int	index;

	if (!(*stk))
		return (-1);
	i = (*stk)->t;
	index = (*stk)->t;
	while (i < (*stk)->sz)
	{
		if (compare == 0 && (*stk)->s[i] < (*stk)->s[index])
			index = i;
		if (compare == 1 && (*stk)->s[i] > (*stk)->s[index])
			index = i;
		i++;
	}
	return (index);
}

/*
	@brief		gmb		Get Max Bit
	@param a	Stack a
	@return		This function will return the maximum number
				of bits in the stack.
*/
int	gmb(t_stack **a)
{
	int	b;
	int	max;

	if (!(*a))
		return (-1);
	b = 0;
	max = (*a)->s[gmi(a, 1)];
	while (max > 0)
	{
		b++;
		max >>= 1;
	}
	return (b);
}

/*
	@brief	asi	Assign Index
	@param	a	Stack A
*/
void	asi(t_stack **a)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	if (!(*a))
		return ;
	temp = (int *)malloc(sizeof(int) * (*a)->sz);
	if (!temp)
		return ;
	i = -1;
	while (++i < (*a)->sz)
	{
		k = 0;
		j = -1;
		while (++j < (*a)->sz)
			if ((*a)->s[i] > (*a)->s[j])
				k++;
		temp[i] = k;
	}
	i = (*a)->sz;
	while (i--)
		(*a)->s[i] = temp[i];
	free(temp);
}

int	hamad_sort_small_b(t_stack **a, t_stack **b)
{
	int	mi;

	if (!(*a) || !(*b))
		return (0);
	if (is_sorted(b, 1) || is_empty(b) || (*b)->t + 1 == (*b)->sz)
		return (hamad_sort_small_a(a, b));
	mi = gmi(b, 1);
	if (mi == (*b)->t && is_sorted(a, 0))
		return (pa(a, b, 0), hamad_sort_small_a(a, b));
	if (mi <= (((*b)->sz - 1) / 2))
		return (rb(b, 1), hamad_sort_small_a(a, b));
	if ((*a)->s[(*a)->t] > (*a)->s[(*a)->t + 1]
		&& (*b)->s[(*b)->t] < (*b)->s[(*b)->t + 1])
		return (ss(a, b, 2), hamad_sort_small_a(a, b));
	if ((*b)->s[(*b)->t] < (*b)->s[(*b)->t + 1])
		return (sb(b, 1), hamad_sort_small_a(a, b));
	if (mi > (((*b)->sz - 1) / 2))
		return (rrb(b, 1), hamad_sort_small_a(a, b));
	return (hamad_sort_small_a(a, b));
}

/*
	@param	a	stack a
	@param	b	stack b
	@var	mi	min index
	@return Will return 1 if sorting is successful and
	0 if sorting is unsuccessful/error
*/
int	hamad_sort_small_a(t_stack **a, t_stack **b)
{
	int	mi;

	if (!(*a) || !(*b))
		return (0);
	if (is_sorted(a, 0) && is_empty(b))
		return (1);
	if (is_sorted(a, 0) && is_sorted(b, 1) && !is_empty(b))
		return (pa(a, b, 0), hamad_sort_small_a(a, b));
	if (is_sorted(a, 0) && !is_empty(b))
		return (hamad_sort_small_b(a, b));
	mi = gmi(a, 0);
	if ((*a)->s[(*a)->t] > (*a)->s[(*a)->sz - 1] && mi <= ((*a)->sz - 1) / 2)
		return (ra(a, 0), hamad_sort_small_b(a, b));
	if (!is_empty(b) && (*a)->s[(*a)->t] > (*a)->s[(*a)->t + 1]
		&& (*b)->s[(*b)->t] < (*b)->s[(*b)->t + 1])
		return (ss(a, b, 2), hamad_sort_small_b(a, b));
	if ((*a)->s[(*a)->t] > (*a)->s[(*a)->t + 1])
		return (sa(a, 0), hamad_sort_small_b(a, b));
	if ((*a)->s[(*a)->t] < (*a)->s[(*a)->sz - 1])
		return (pb(a, b, 1), hamad_sort_small_b(a, b));
	return (rra(a, 0), hamad_sort_small_b(a, b));
}

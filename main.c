/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:14:47 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/31 15:01:06 by h                ###   ########.fr       */
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
// Use this for testing: https://appzaza.com/random-number-generator

#include "push_swap.h"

int	intit_stack(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		i;
	long	temp;
	char	**s;

	(*a) = (t_stack *)malloc(sizeof(t_stack));
	(*b) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*a) || !(*b))
		return (0);
	i = 1;
	temp = 0;
	while (argv[i])
	{
		s = ft_split(argv[i++], ' ');
		if (!s)
			return (0);
		temp += count_split(s);
		free_split(s);
	}
	(*a)->s = (int *)malloc(sizeof(int) * (temp));
	(*b)->s = (int *)malloc(sizeof(int) * (temp));
	if (!(*a)->s || !(*b)->s)
		return (0);
	return ((*a)->sz = temp, (*a)->t = 0,
		(*b)->sz = temp, (*b)->t = temp, assign_num(a, argc, argv));
}

int	print_stack(t_stack **stk)
{
	int	i;

	if (!(*stk))
		return (0);
	i = 0;
	while (i < (*stk)->sz)
	{
		ft_printf("(*stk)->s[%d]: %d\n", i, (*stk)->s[i]);
		i++;
	}
	ft_printf("\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		if (check_arg_input(argc, ft_split(argv[1], ' ')) == 0
			|| intialize_stack_arg(&a, &b, ft_split(argv[1], ' ')) == 0
			|| !is_unique(&a))
			return (fs(&a, &b), ft_putendl_fd("\e[31mError\e[0m", 2), 2);
	}
	else
	{
		if (check_input(argc, argv) == 0 || intit_stack(&a, &b, argc,
				argv) == 0 || !is_unique(&a))
			return (fs(&a, &b), ft_putendl_fd("\e[31mError\e[0m", 2), 2);
	}
	if (is_sorted(&a, 0))
		return (fs(&a, &b), 0);
	if (a->sz <= 6)
		hamad_sort_small_a(&a, &b);
	else
		hamad_radix(&a, &b);
	return (fs(&a, &b), 0);
}

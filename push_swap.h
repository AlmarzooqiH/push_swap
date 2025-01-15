/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h <h@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:10:24 by hamalmar          #+#    #+#             */
/*   Updated: 2024/08/27 13:47:17 by h                ###   ########.fr       */
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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*
	This struct represents a stack data structure.
	@var sz stands for size
	@var t stands for top_index
	@var s stands for stack
*/
typedef struct s_stack
{
	int	sz;
	int	t;
	int	*s;
}		t_stack;

int		intit_stack(t_stack **a, t_stack **b, int argc, char **argv);
int		intialize_stack_arg(t_stack **a, t_stack **b, char **split);
int		print_stack(t_stack **stack);
int		get_splitsize(char **s);
int		assign_num(t_stack **a, int ac, char **av);
int		check_input(int ac, char **av);
int		check_arg_input(int argc, char **argv);
int		is_unique(t_stack **a);
int		is_unique_ARG(int argc, char **argv);
int		is_sorted(t_stack **a, int compare);
int		count_split(char **argv);
int		check_space(char *s);
int		check_isnum(char *s);
int		is_empty(t_stack **stk);
void	fs(t_stack **a, t_stack **b);
int		sa(t_stack **a, int from);
int		sb(t_stack **b, int from);
int		ss(t_stack **a, t_stack **b, int from);
int		pa(t_stack **a, t_stack **b, int from);
int		pb(t_stack **a, t_stack **b, int from);
int		ra(t_stack **a, int from);
int		rb(t_stack **b, int from);
int		rr(t_stack **a, t_stack **b, int from);
int		rra(t_stack **a, int from);
int		rrb(t_stack **b, int from);
int		rrr(t_stack **a, t_stack **b, int from);
int		gmi(t_stack **a, int compare);
int		gmb(t_stack **a);
void	asi(t_stack **a);
int		hamad_radix(t_stack **a, t_stack **b);
int		hamad_sort_small_a(t_stack **a, t_stack **b);
int		hamad_sort_small_b(t_stack **a, t_stack **b);

#endif
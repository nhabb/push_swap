/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:07:05 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:07:05 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b,
		int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(stack_a, stack_b);
		(*pos_a)--;
		(*pos_b)--;
	}
	while (*pos_a > 0)
	{
		ra(stack_a);
		(*pos_a)--;
	}
	while (*pos_b > 0)
	{
		rb(stack_b);
		(*pos_b)--;
	}
}

void	rev_rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b,
		int *pos_a, int *pos_b)
{
	int	size_a;
	int	size_b;

	size_a = count_nodes(*stack_a);
	size_b = count_nodes(*stack_b);
	while (*pos_a < size_a && *pos_b < size_b)
	{
		rrr(stack_a, stack_b);
		(*pos_a)++;
		(*pos_b)++;
	}
	while (*pos_a < size_a)
	{
		rra(stack_a);
		(*pos_a)++;
	}
	while (*pos_b < size_b)
	{
		rrb(stack_b);
		(*pos_b)++;
	}
}

void	rotate_a(t_stack_node **stack_a, int pos_a, int size_a)
{
	if (pos_a <= size_a / 2)
	{
		while (pos_a > 0)
		{
			ra(stack_a);
			pos_a--;
		}
	}
	else
	{
		while (pos_a < size_a)
		{
			rra(stack_a);
			pos_a++;
		}
	}
}

void	rotate_b(t_stack_node **stack_b, int pos_b, int size_b)
{
	if (pos_b <= size_b / 2)
	{
		while (pos_b > 0)
		{
			rb(stack_b);
			pos_b--;
		}
	}
	else
	{
		while (pos_b < size_b)
		{
			rrb(stack_b);
			pos_b++;
		}
	}
}

void	rotate_stacks(t_stack_node **stack_a, t_stack_node **stack_b, int pos_a,
		int pos_b)
{
	int	size_b;
	int	size_a;

	size_a = count_nodes(*stack_a);
	size_b = count_nodes(*stack_b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		rotate_both_rr(stack_a, stack_b, &pos_a, &pos_b);
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
		reverse_rotate_both_rrr(stack_a, stack_b, &pos_a, &pos_b);
	else
	{
		rotate_stack_a(stack_a, pos_a, size_a);
		rotate_stack_b(stack_b, pos_b, size_b);
	}
}

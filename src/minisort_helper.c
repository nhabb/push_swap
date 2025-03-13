/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:25:24 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 20:22:17 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*largest;

	largest = find_max(*stack);
	if (*stack == largest)
		ra(stack, 1);
	else if ((*stack)->next == largest)
		rra(stack, 1);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack, 1);
}

t_stack_node	*find_min(t_stack_node *stack_a)
{
	t_stack_node	*min;

	min = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->number < min->number)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	assign_indices(*a);
	min = find_min(*a);
	while (min->position != 1)
	{
		if (min->median == 1)
			ra(a, 1);
		else
			rra(a, 1);
		assign_indices(*a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	assign_indices(*a);
	min = find_min(*a);
	while (min->position != 1)
	{
		if (min->median == 1)
			ra(a, 1);
		else
			rra(a, 1);
		assign_indices(*a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_two(t_stack_node **a)
{
	if ((*a)->number > (*a)->next->number)
		ra(a, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:02:23 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 19:31:28 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_and_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheap)
{
	while (cheap->position != 1 && cheap->target->position != 1)
	{
		rr(stack_a, stack_b);
		assign_indices(*stack_a);
		assign_indices(*stack_b);
	}
}

void	reverse_rotate_a_and_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (cheapest->position != 1 && cheapest->target->position != 1)
	{
		rrr(stack_a, stack_b);
		assign_indices(*stack_a);
		assign_indices(*stack_b);
	}
}

void	put_node_on_top_a(t_stack_node **stack_a, t_stack_node *cheapest)
{
	while (cheapest->position != 1)
	{
		if (cheapest->median == 1)
		{
			ra(stack_a, 1);
		}
		else
			rra(stack_a, 1);
		assign_indices(*stack_a);
	}
}

void	put_node_on_top_b(t_stack_node **stack_b, t_stack_node *cheapest)
{
	while (cheapest->target->position != 1)
	{
		if (cheapest->target->median == 1)
		{
			rb(stack_b, 1);
		}
		else
			rrb(stack_b, 1);
		assign_indices(*stack_b);
	}
}

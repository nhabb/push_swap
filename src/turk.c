/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:02:34 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 19:37:46 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	assign_indices(*stack_a);
	assign_indices(*stack_b);
	set_target_of_a(*stack_a, *stack_b);
	calculate_cost(*stack_a);
	calculate_cost(*stack_b);
	combined_cost(*stack_a, stack_b);
}

void	sort_max(t_stack_node **stack_b)
{
	t_stack_node	*max;

	max = find_max(*stack_b);
	assign_indices(*stack_b);
	while (max->position != 1)
	{
		if (max->median == 1)
			rb(stack_b, 1);
		else if (max->median == 0)
			rrb(stack_b, 1);
		assign_indices(*stack_b);
	}
}

void	sort(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*cheap;

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while (count_nodes(stack_a) > 0)
	{
		pre_sort(&stack_a, &stack_b);
		cheap = cheapest_node(stack_a);
		if (cheap->median == 1 && cheap->target->median == 1)
			rotate_a_and_b(&stack_a, &stack_b, cheap);
		else if (cheap->median == 0 && cheap->target->median == 0)
			reverse_rotate_a_and_b(&stack_a, &stack_b, cheap);
		put_node_on_top_a(&stack_a, cheap);
		put_node_on_top_b(&stack_b, cheap);
		pb(&stack_a, &stack_b);
	}
	sort_max(&stack_b);
	while (stack_b != NULL)
		pa(&stack_b, &stack_a);
	free_list(stack_a);
}

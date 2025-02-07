/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:01:29 by nhaber            #+#    #+#             */
/*   Updated: 2024/09/16 19:01:29 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rotation_cost(int index, int total_nodes)
{
	if (index <= total_nodes / 2)
		return (index);
	else
		return (total_nodes - index);
}

int	max_cost(int cost1, int cost2)
{
	if (cost1 > cost2)
		return (cost1);
	else
		return (cost2);
}

int	calculate_combined_cost(t_stack_node *node_a, t_stack_node *node_b,
							int total_nodes_a, int total_nodes_b)
{
	int	cost_a;
	int	cost_b;
	int	combined_cost;

	cost_a = calculate_rotation_cost(node_a->index, total_nodes_a);
	cost_b = calculate_rotation_cost(node_b->index, total_nodes_b);
	if ((node_a->index <= total_nodes_a / 2
			&& node_b->index <= total_nodes_b / 2)
		|| (node_a->index > total_nodes_a / 2
			&& node_b->index > total_nodes_b / 2))
	{
		combined_cost = max_cost(cost_a, cost_b);
	}
	else
		combined_cost = cost_a + cost_b;
	return (combined_cost);
}

t_stack_node	*cheapest_node(t_stack_node *stack_a, t_stack_node *stack_b,
							int total_a, int total_b)
{
	 t_stack_node	*current_node_a;
	 t_stack_node	*cheapest_node;
	int				min_cost;
	int				current_cost;

	current_node_a = stack_a;
	cheapest_node = stack_a;
	min_cost = INT_MAX;
	while (current_node_a != NULL)
	{
		// if (current_node_a->target == NULL)
		// {
			set_target_node_a(stack_b, current_node_a);
		// }
		
		current_cost = calculate_combined_cost(current_node_a,
				current_node_a->target, total_a, total_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_node = current_node_a;
			// printf("cheapest node is %lld\n", cheapest_node->data);
		}
		// printf("%lld is target of   %lld: \n",current_node_a->target->data, current_node_a->data);

		// if(cheapest_node->cost > current_node_a->cost)
		// {
		// 	cheapest_node = current_node_a;
		// }
		current_node_a = current_node_a->next;
	}
	return (cheapest_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:29:45 by wasmar            #+#    #+#             */
/*   Updated: 2025/02/24 19:24:38 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_stack_node *head)
{
	int	size_list;

	size_list = count_nodes(head);
	while (head != NULL)
	{
		if (head->median == 1)
			head->cost = (head->position) - 1;
		else
			head->cost = size_list - (head->position) + 1;
		head = head->next;
	}
}

void	combined_cost(t_stack_node *stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	while (stack_a != NULL)
	{
		temp = *stack_b;
		while (temp != NULL)
		{
			if (stack_a->target->number == temp->number)
			{
				stack_a->cost += temp->cost;
				break ;
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

t_stack_node	*cheapest_node(t_stack_node *head)
{
	t_stack_node	*cheapest;
	t_stack_node	*curr;

	cheapest = head;
	curr = head;
	if (head == NULL)
		return (NULL);
	while (curr != NULL)
	{
		if (cheapest->cost > curr->cost)
		{
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

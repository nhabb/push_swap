/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:06:23 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:06:23 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	find_min(t_stack_node *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack_node *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	iterate_stack(t_stack_node **stack, t_stack_node *current, int value,
		int prev_value)
{
	int	i;

	i = 0;
	while (i < count_nodes(*stack))
	{
		if ((value > prev_value && value < current->data)
			|| (prev_value > current->data && (value > prev_value
					|| value < current->data)))
			return (i);
		prev_value = current->data;
		current = current->next;
		if (!current)
			current = *stack;
		i++;
	}
	return (0);
}

int	find_optimal_position_increasing(t_stack_node *stack, int value)
{
	t_stack_node	*current;
	int				position;
	int				prev_value;

	if (!stack)
		return (0);
	current = stack;
	position = 0;
	if (value < find_min(stack) || value > find_max(stack))
	{
		while (current && current->data != find_max(stack))
		{
			position++;
			current = current->next;
		}
		return ((position + 1) % count_nodes(stack));
	}
	current = stack;
	if (current->next)
		prev_value = current->data;
	else
		prev_value = find_min(stack);
	return (iterate_over_stack(&stack, current, value, prev_value));
}

int	stack_decreasing(t_stack_node **stack, t_stack_node *current,
		int value, int prev_value)
{
	int	i;

	i = 0;
	while (i < count_nodes(*stack))
	{
		if ((value < prev_value && value > current->data)
			|| (prev_value < current->data && (value < prev_value
					|| value > current->data)))
			return (i);
		prev_value = current->data;
		current = current->next;
		if (!current)
			current = *stack;
		i++;
	}
	return (0);
}

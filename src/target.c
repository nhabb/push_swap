/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:33:09 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:58:58 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max_num_pointer(t_stack_node *head)
{
	t_stack_node	*max;

	max = head;
	while (head != NULL)
	{
		if (head->number > max->number)
			max = head;
		head = head->next;
	}
	return (max);
}

void	target(t_stack_node *new_b, t_stack_node *stack_a, int *i)
{
	while (new_b != NULL)
	{
		if (*i == 0)
		{
			if (new_b->number < stack_a->number)
			{
				stack_a->target = new_b;
				(*i)++;
			}
		}
		else
		{
			if (new_b->number < stack_a->number
				&& new_b->number > stack_a->target->number)
				stack_a->target = new_b;
		}
		new_b = new_b->next;
	}
}

void	set_target_of_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*new_b;
	int				i;

	new_b = stack_b;
	i = 0;
	while (stack_a != NULL)
	{
		new_b = stack_b;
		i = 0;
		target(new_b, stack_a, &i);
		if (i == 0)
			stack_a->target = find_max_num_pointer(stack_b);
		stack_a = stack_a->next;
	}
}

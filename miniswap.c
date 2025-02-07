/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:20:11 by nhaber            #+#    #+#             */
/*   Updated: 2024/09/03 21:20:11 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_helper(t_stack_node **stack_a, long long int first,
			long long int second,long long int third)
{
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

t_stack_node	*sort_three(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	long long int				first;
	long long int				second;
	long long int				third;

	temp = *stack_a;
	if (!temp || !temp->next || !temp->next->next)
		return (*stack_a);
	first = temp->data;
	second = temp->next->data;
	third = temp->next->next->data;
	sort_three_helper(stack_a, first, second, third);
	return (*stack_a);
}

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				count;
	int				nodes;
	t_stack_node	*temp;

	temp = (*stack_a);
	count = 0;
	nodes = count_nodes(*stack_a);
	while (temp != NULL && count < 2)
	{
		if (nodes > 3)
		{
			pb(stack_a, stack_b);
			count++;
			nodes--;
		}
		temp = (*stack_a);
	}
}

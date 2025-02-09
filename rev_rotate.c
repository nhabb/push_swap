/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:14:32 by nhaber            #+#    #+#             */
/*   Updated: 2024/08/26 11:14:32 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	last = (*stack_a);
	second_last = NULL;
	while ((last)->next != NULL)
	{
		second_last = (last);
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = (*stack_a);
	*stack_a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	last = (*stack_b);
	second_last = NULL;
	while ((last)->next != NULL)
	{
		second_last = (last);
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = (*stack_b);
	*stack_b = last;
	ft_printf("rrb\n");
}
void	rrb1(t_stack_node **stack_b)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	last = (*stack_b);
	second_last = NULL;
	while ((last)->next != NULL)
	{
		second_last = (last);
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = (*stack_b);
	*stack_b = last;
	// ft_printf("rrb\n");
}
void	rra1(t_stack_node **stack_a)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	last = (*stack_a);
	second_last = NULL;
	while ((last)->next != NULL)
	{
		second_last = (last);
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = (*stack_a);
	*stack_a = last;
	// ft_printf("rra\n");
}
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra1(stack_a);
	rrb1(stack_b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:20:15 by nhaber            #+#    #+#             */
/*   Updated: 2024/08/25 22:20:15 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*temp2;

	temp = (*stack_a);
	temp2 = (*stack_a)->next;
	while ((*stack_a) != NULL && (*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->next = NULL;
	(*stack_a) = temp2;
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	t_stack_node	*temp;
	t_stack_node	*temp2;

	temp = (*stack_b);
	temp2 = (*stack_b)->next;
	while ((*stack_b) != NULL && (*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->next = NULL;
	(*stack_b) = temp2;
	ft_printf("rb\n");
}

void	ra1(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*temp2;

	temp = (*stack_a);
	temp2 = (*stack_a)->next;
	while ((*stack_a) != NULL && (*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->next = NULL;
	(*stack_a) = temp2;
	// ft_printf("ra\n");
}

void	rb1(t_stack_node **stack_b)
{
	t_stack_node	*temp;
	t_stack_node	*temp2;

	temp = (*stack_b);
	temp2 = (*stack_b)->next;
	while ((*stack_b) != NULL && (*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->next = NULL;
	(*stack_b) = temp2;
	// ft_printf("rb\n");
}
void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra1(stack_a);
	rb1(stack_b);
	ft_printf("rr\n");
}

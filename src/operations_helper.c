/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:38 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 17:32:50 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*temp;
	t_stack_node	*temp1;

	temp = (*head);
	temp = temp->next;
	temp1 = (*head)->next->next;
	(*head)->next = temp->next;
	temp->next = (*head);
	(*head)->prev = temp;
	temp1->prev = (*head);
	temp->prev = NULL;
	(*head) = temp;
}

void	rotate(t_stack_node **head)
{
	t_stack_node	*temp;
	t_stack_node	*temp1;

	temp1 = (*head)->next;
	temp = *head;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = temp;
	temp->prev = (*head);
	temp->next = NULL;
	temp1->prev = NULL;
	(*head) = temp1;
	temp1 = NULL;
}

void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*new_last;

	first_node = (*head);
	new_last = (*head);
	while (new_last->next != NULL)
	{
		new_last = new_last->next;
	}
	new_last = new_last->prev;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = first_node;
	first_node->prev = (*head);
	(*head)->prev = NULL;
	new_last->next = NULL;
}

void	push(t_stack_node **send_form, t_stack_node **send_to)
{
	t_stack_node	*temp;

	if (*send_form == NULL)
		return ;
	temp = *send_form;
	*send_form = (*send_form)->next;
	if (*send_form != NULL)
	{
		(*send_form)->prev = NULL;
	}
	temp->next = *send_to;
	temp->prev = NULL;
	if (*send_to != NULL)
	{
		(*send_to)->prev = temp;
	}
	*send_to = temp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:30:23 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 19:30:35 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Create a new node and return it.
 * Set the number to the value given as a parameter.
 * Set the prev and next pointers to NULL.
 */
t_stack_node	*create_node(int num)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	new_node->number = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	return_to_top(t_stack_node **node)
{
	while ((*node)->prev != NULL)
	{
		(*node) = (*node)->prev;
	}
}

void	free_list(t_stack_node *node)
{
	t_stack_node	*temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

int	count_nodes(t_stack_node *temp)
{
	int	i;

	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

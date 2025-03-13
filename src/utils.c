/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:55 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:59:03 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_list(int *input, int count, int flag)
{
	t_stack_node	*first_node;
	t_stack_node	*new_node;
	t_stack_node	*head;
	int				i;

	i = 1;
	first_node = create_node(input[0]);
	head = first_node;
	if (flag == 1)
		count = count - 1;
	while (i < count)
	{
		new_node = create_node(input[i]);
		head->next = new_node;
		new_node->prev = head;
		head = head->next;
		i++;
	}
	return_to_top(&head);
	return (head);
}

void	free_2d_array(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	free_and_exit_1(t_input *input, int *data, t_stack_node **stack_a)
{
	free(input);
	free(data);
	free_list(*stack_a);
	exit(0);
}

void	free_and_exit_if_sorted(int *data, t_stack_node **stack_a)
{
	free(data);
	free_list(*stack_a);
	exit(0);
}

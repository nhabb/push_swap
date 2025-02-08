/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:36:02 by nhaber            #+#    #+#             */
/*   Updated: 2024/09/02 13:36:02 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf(" %lld", stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	free_list(t_stack_node *stack_a)
{
	t_stack_node	*temp;

	while (stack_a != NULL)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
}

bool	input_to_stack(int argc, char **argv, t_stack_node **stack_a)
{
	int						i;
	long long int			input;
	bool						success;

	i = 1;
	while (i < argc)
	{
		if (numerical_param(argv[i]) == true)
		{
			ft_printf ("ERROR1\n");
			exit (0);
		}
		if (extra_cases(argv[i]))
		{
			ft_printf("ERROR2\n");
			exit (1);
		}
		success = new_atoi(argv[i], &input);
		if (!success)
        {
            ft_printf("ERRORxfgdfg\n");
            exit (1);
        }
		correct_order(stack_a, input);
		i++;
	}
	return (false);
}
void	correct_order(t_stack_node	**stack_a, long long int input)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->data = input;
	new_node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	new_node = (*stack_a);
	// printf("ana stack A:\n");
	// print_stack(*stack_a);
}

int	count_nodes(t_stack_node *stack_a)
{
	int	count;

	count = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		count++;
	}
	return (count);
}

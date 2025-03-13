/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:44:23 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 20:25:05 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices_even(t_stack_node *head, int list_size)
{
	int	i;

	i = 1;
	while (head != NULL)
	{
		head->position = i;
		if (i <= list_size / 2)
			head->median = 1;
		else
			head->median = 0;
		head = head->next;
		i++;
	}
}

void	assign_indices(t_stack_node *head)
{
	int	i;
	int	list_size;

	i = 1;
	list_size = count_nodes(head);
	if (list_size % 2 != 0)
	{
		while (head != NULL)
		{
			head->position = i;
			if (i <= list_size / 2 + 1)
				head->median = 1;
			else
				head->median = 0;
			head = head->next;
			i++;
		}
	}
	else
		assign_indices_even(head, list_size);
}

t_stack_node	*find_max(t_stack_node *head)
{
	t_stack_node	*max;

	max = head;
	while (head != NULL)
	{
		if (max->number < head->number)
			max = head;
		head = head->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (argc != 1)
	{
		if (argc == 2)
			quoted_arg(argv[1], &stack_a);
		else if (argc > 2)
			non_quoted_arg(&stack_a, argv, argc);
		mini_sort(&stack_a, &stack_b);
	}
	else
	{
		exit(0);
	}
}

bool	check_str(char **av)
{
	int	i;
	int	j;
	int	number;

	i = 1;
	while (av[i])
	{
		j = 0;
		number = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
			{
				if (number > 0 && av[i][j - 1] == ' ')
					return (false);
				number++;
			}
			j++;
		}
		i++;
	}
	return (true);
}

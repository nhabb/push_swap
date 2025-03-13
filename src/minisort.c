/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:35 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 20:38:55 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quoted_arg(char *argv, t_stack_node **stack_a)
{
	t_input	*input;
	int		*data;
	bool	error;
	int		i;

	error = true;
	check_space(argv);
	check_negative(argv);
	input = malloc(sizeof(t_input));
	error = split_argument(argv, &input, &data);
	if (error == false)
	{
		free(input);
		write(2, "Error\n", 5);
		exit(0);
	}
	(*stack_a) = create_list(data, input->input_count, 0);
	i = count_nodes(*stack_a);
	if (i == 1)
		free_and_exit_1(input, data, stack_a);
	quoted_arg_helper(&input, stack_a, check_duplicate(*stack_a), &data);
	quoted_arg_helper1(&input, stack_a, already_sorted(*stack_a), &data);
	free(data);
	free(input);
}

void	check_space(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
		{
			j++;
		}
		i++;
	}
	if (j == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	mini_pre_sort(t_stack_node ***stack_a, t_stack_node ***stack_b)
{
	if (count_nodes(**stack_a) == 2)
	{
		sort_two(*stack_a);
		free_list(**stack_a);
		free_list(**stack_b);
	}
	else if (count_nodes(**stack_a) == 3)
	{
		sort_three(*stack_a);
		free_list(**stack_a);
		free_list(**stack_b);
	}
}

void	mini_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (count_nodes(*stack_a) == 3 || count_nodes(*stack_a) == 2)
		mini_pre_sort(&stack_a, &stack_b);
	else if (count_nodes(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
		free_list(*stack_a);
		free_list(*stack_b);
	}
	else if (count_nodes(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
		free_list(*stack_a);
		free_list(*stack_b);
	}
	else
		sort(*stack_a, *stack_b);
}

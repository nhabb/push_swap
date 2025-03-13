/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:30:57 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 20:40:18 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	non_quoted_arg_error(int *data, bool error)
{
	if (error == false)
	{
		free(data);
		write(2, "Error", 5);
		exit(0);
	}
}

void	check_str_helper(char **av)
{
	if (check_str(av) == false)
	{
		write(2, "Error", 5);
		exit(0);
	}
}

void	non_quoted_arg(t_stack_node **stack_a, char **argv, int argc)
{
	bool	error2;
	bool	error1;
	int		*data;

	check_str_helper(argv);
	data = malloc((argc - 1) * sizeof(int));
	non_quoted_arg_error(data, parse_input(argv, argc, &data));
	non_quoted_arg_error(data, is_numeric(argv, 1));
	(*stack_a) = create_list(data, argc, 1);
	error2 = true;
	error1 = check_duplicate(*stack_a);
	if (error1 == false)
	{
		free(data);
		free_list(*stack_a);
		write(2, "Error", 5);
		exit(0);
	}
	error2 = already_sorted(*stack_a);
	if (error2 == false)
		free_and_exit_if_sorted(data, stack_a);
	free(data);
}

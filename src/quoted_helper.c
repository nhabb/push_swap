/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:24:29 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 20:25:05 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quoted_arg_helper(t_input **input, t_stack_node **stack_a,
		bool indicator, int **data)
{
	if (indicator == false)
	{
		free(*input);
		free(*data);
		free_list(*stack_a);
		write(2, "Error\n", 5);
		exit(0);
	}
}

void	quoted_arg_helper1(t_input **input, t_stack_node **stack_a,
		bool indicator, int **data)
{
	if (indicator == false)
	{
		free(*input);
		free(*data);
		free_list(*stack_a);
		exit(0);
	}
}

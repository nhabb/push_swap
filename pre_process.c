/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:06:36 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:06:36 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack_node	*pre_sort(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
	if (argc < 2)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	if (argc == 2)
		subprocess(&a, argv);
	else
		multi_arg_process(&a, argv);
	return (a);
}

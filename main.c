/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 17:14:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;

	a = pre_process(argc, argv);
	if (!a || find_dup(&a))
	{
		free_list(a);
		ft_printf("ERROR\n");
        exit(1);
	}
	if (!already_sorted(a))
		sort(&a);
	free_list(a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:07:15 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:07:15 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **a)
{
	t_stack_node	*b;

	b = NULL;
	if (count_nodes(*a) > 4)
		pb(a, &b);
	pb(a, &b);
	while (count_nodes(*a) > 3)
		calculate_cheapest(a, &b);
	sort_three(a);
	merge_stacks(a, &b);
	final_arrangement(a);
}

void	sort(t_stack_node **a)
{
	int	size;

	size = count_nodes(*a);
	if (size == 2)
	{
		sort_two_stack(a);
		free_list(*a);
		exit(1);
	}
	if (size == 3)
		sort_three(a);
	else
		sort_large_stack(a);
}

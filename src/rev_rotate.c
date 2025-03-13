/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:30:21 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 17:50:02 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **head, int flag)
{
	reverse_rotate(head);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **head, int flag)
{
	reverse_rotate(head);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **head_a, t_stack_node **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	write(1, "rrr\n", 4);
}

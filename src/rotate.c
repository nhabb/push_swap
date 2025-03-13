/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:34:05 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:58:27 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack_node **head_a, t_stack_node **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	write(1, "rr\n", 3);
}

void	ra(t_stack_node **head, int flag)
{
	rotate(head);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **head, int flag)
{
	rotate(head);
	if (flag == 1)
		write(1, "rb\n", 3);
}

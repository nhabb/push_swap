/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:39:38 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:58:19 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **head_a, t_stack_node **head_b)
{
	push(head_a, head_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **head_a, t_stack_node **head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}

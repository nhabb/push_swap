/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:37:41 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:58:35 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **head, int flag)
{
	swap(head);
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **head, int flag)
{
	swap(head);
	if (flag == 1)
		write(1, "sb\n", 3);
}

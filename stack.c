/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:07:28 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:07:28 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

t_stack_node	*new_stack(int content)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
	{
		ft_printf("Erorr");
		exit(1);
	}
	new->data = content;
	new->next = NULL;
	return (new);
}

t_stack_node	*ft_lstlast1(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack_node	*stack_add_back(t_stack_node **stack, t_stack_node *new)
{
	if (!stack)
		return (new);
	if (!*stack)
		*stack = new;
	else
		(ft_lstlast1(*stack))->next = new;
	return (*stack);
}

void	merge(t_stack_node **a, t_stack_node **b)
{
	int	pos_a;
	int	size_a;

	while (*b)
	{
		pos_a = find_optimal_position_increasing(*a, (*b)->data);
		size_a = count_nodes(*a);
		if (pos_a <= size_a / 2)
		{
			while (pos_a-- > 0)
				ra(a);
		}
		else
		{
			while (pos_a++ < size_a)
				rra(a);
		}
		pa(a, b);
	}
}

void	final_form(t_stack_node **a)
{
	t_stack_node	*current;
	int				pos;
	int				min;
	int				size;

	current = *a;
	pos = 0;
	min = find_min(*a);
	size = count_nodes(*a);
	while (current->data != min)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

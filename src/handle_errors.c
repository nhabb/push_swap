/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:54:28 by nhaber            #+#    #+#             */
/*   Updated: 2024/08/24 11:54:28 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_bounds(char *str)
{
	char	*max = "2147483647";
	char	*min = "-2147483648";

	if (*str == '-')
	{
		if (!strcmp_max(min + 1, str + 1))
			ft_printf("ERROR\n");
	}
	else
	{
		if (!strcmp_max(max , str))
			ft_printf("ERROR\n");
	}
}

int	already_sorted(t_stack_node *head)
{
	t_stack_node	*tail;
	t_stack_node	*temp;

	tail = head;
	temp = head;
	while (tail != NULL && tail->next != NULL)
		tail = tail->next;
	while(temp != NULL && temp->next != NULL)
	{
		if (temp->next->data > temp->data)
			temp = temp->next;
		else
			return (0);
	}
	if (tail == temp)
		return (1);
	temp = head;
	return (1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:18 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 19:26:02 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	already_sorted(t_stack_node *head)
{
	while (head->next != NULL)
	{
		if (head->number > head->next->number)
		{
			return (true);
		}
		head = head->next;
	}
	return (false);
}

bool	check_duplicate(t_stack_node *head)
{
	t_stack_node	*temp;

	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if (temp->number == head->number)
			{
				return (false);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (true);
}

bool	is_numeric(char **data, int flag)
{
	int	i ;
	int	j;

	i = 0;
	if (flag == 1)
	{
		i = 1;
	}
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == '-' && j != 0)
				return (false);
			if ((data[i][j] < '0' || data[i][j] > '9') && data[i][j] != '-'
				&& data[i][j] != ' ')
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

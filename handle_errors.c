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

bool	already_sorted(t_stack_node *head)
{
	t_stack_node	*tail;
	t_stack_node	*temp;

	tail = head;
	temp = head;
	while (tail != NULL && tail->next != NULL)
		tail = tail->next;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->next->data > temp->data)
			temp = temp->next;
		else
			return (false);
	}
	if (tail == temp)
		return (1);
	temp = head;
	return (true);
}

bool	find_dup(t_stack_node **stack_a)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				found_duplicate;

	found_duplicate = 0;
	current = (*stack_a);
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (compare->data == current->data)
				return (true);
			found_duplicate = 1;
			compare = compare->next;
		}
		current = current->next;
	}
	if (!found_duplicate)
		return (false);
	return (false);
}

bool	numerical_param(char *arg)
{
	int j;

	j = 0;
	if (arg[j] == '-')
	{
		j++;
		if (arg[j] == '-' || arg[j] == '+')
			return (true);
		j++;
	}
	while (arg[j])
	{
		if (arg[j] < '0' || arg[j] > '9')
			return (true);
		j++;
	}
	return (false);
}

bool extra_cases(char *arg)
{
    int i = 0;

    if (arg == NULL || arg[0] == '\0')
        return (false);
    else if (arg[0] == ' ' || arg[ft_strlen(arg) - 1] == ' ')
        return (true);
    while (arg[i] != '\0')
    {
        if (arg[i] == '-')
        {
            if (arg[i + 1] == '\0' || arg[i + 1] == ' ')
                return (true);
            if ((i > 0 && arg[i - 1] == ' ') || (arg[i + 1] != '\0' && arg[i + 1] == ' '))
                return (true);
        }
        i++;
    }
    return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:45:51 by nhaber            #+#    #+#             */
/*   Updated: 2024/08/24 11:45:51 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bool	new_atoi(const char *nptr, long long int *ftatoi)
// {
// 	int			i;
// 	int			sign;
// 	long long int	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	if (nptr[i] == '+' || nptr[i] == '-')
// 	{
// 		if (nptr[i] == '-')
// 			sign *= -1;
// 		i++;
// 		if (nptr[i] == '+' || nptr[i] == '\0')
// 			exit (1);
// 	}
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		result = result * 10 + (nptr[i] - '0');
// 		if (result == 0)
// 			printf("i am 0");
// 		printf("%lld\n", result);
// 		i++;
// 	}
// 	*ftatoi = (result * sign);
// 	if (*ftatoi < -2147483648LL || *ftatoi > 147483647LL)
// 			exit (1);
// 	return (*ftatoi);
// 	// while  (nptr[i])
// 	// {
// 	// 	if (nptr[i] == '-')
// 	// 	{
// 	// 		sign = -1;
// 	// 		i++;
// 	// 	}
// 	// 	if (nptr[i] == '+')
// 	// 		exit(1);
// 	// 	if (nptr[i] >= '0' && nptr[i] <= '9')
// 	// 	{
// 	// 		result = result * 10 + (nptr[i] - '0');
// 	// 		i++;
// 	// 	}
// 	// }	
// 	// return (sign * result);
// }
bool new_atoi(const char *nptr, long long int *ftatoi)
{
    int i = 0;
    int sign = 1;
    long long int result = 0;

    if (nptr[i] == '-')
    {
	    sign *= -1;
        i++;
	}
    if (nptr[i] == '\0' || nptr[i] == '+') // Invalid cases
            return false;
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        if ((result * sign) < LLONG_MIN || (result * sign) > LLONG_MAX) // Overflow check
            return false;
        i++;
    }
    if (nptr[i] != '\0') // Ensure no extra invalid characters
        return false;
    *ftatoi = result * sign;
    return true;
}

t_stack_node	*find_max_b(t_stack_node **stack_b)
{
	t_stack_node	*temp;
	t_stack_node	*max;

	if (*stack_b == NULL)
		return (NULL);
	temp = *stack_b;
	max = temp;	
	while (temp != NULL)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack_node	*find_min_b(t_stack_node **stack_b)
{
	t_stack_node	*temp;
	t_stack_node	*min;

	if (*stack_b == NULL)
		return (0);
	temp = *stack_b;
	min = temp;
	while (temp != NULL)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	free_main(t_stack_node *stack_a, t_stack_node *stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
}
void assign_indices(t_stack_node *stack)
{
    int index = 0;
	int count = count_nodes(stack);
    while (stack != NULL)
    {
		if(count >= count/2)
		{
			stack->median = 1;
		}
		else
		{
			stack->median = 0;
		}
		stack->median = 0;
        stack->index = index;
        stack = stack->next;
		// print_stack(stack);
		// printf("\n");
        index++;
    }
}

// int findPos(t_stack_node *node,t_stack_node **stack_a)
// {
// 	t_stack_node *current;

// 	current = (*stack_a);
// 	int count;
// 	count = 1;
// 	while(current != NULL)
// 	{
// 		if ((current)->data == node->data)
// 			return count;
// 		count++;
// 		current = current->next;
// 	}
// 	// free(node);
// 	// free_list(*stack_a);
// 	return count;
// }
// void assign_indices(t_stack_node *stack)
// {
// 	int count = count_nodes(stack);
	
// }
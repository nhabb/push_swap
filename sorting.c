/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:48:52 by nhaber            #+#    #+#             */
/*   Updated: 2024/09/12 11:48:52 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void set_target_node_a(t_stack_node **stack_a, t_stack_node **node)
{
    int closest_smaller = INT_MIN;  // Holds the closest smaller value
    t_stack_node *temp = NULL;      // Tracks the potential target node
    t_stack_node *current = (*stack_a);

    // Iterate through stack_a
    while (current != NULL)
    {
        // Check if current node's data is less than node's data and greater than closest_smaller
        if (current->data < (*node)->data && current->data > closest_smaller)
        {
            closest_smaller = current->data;
            temp = current;
        }
        current = current->next;
    }

    // If no smaller element was found, set target to the maximum node in stack_a
    if (temp == NULL)
        (*node)->target = find_max_b(stack_a);
    else
        (*node)->target = temp;
}

void	find_cost(t_stack_node *head)
{
	int	size_list;

	size_list = count_nodes(head);
	while (head != NULL)
	{
		if (head->median == 1)
			head->cost = (head->index) - 1;
		else
			head->cost = size_list - (head->index) + 1;
		head = head->next;
	}
}
void	add_cost_of_a_and_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	temp = *stack_b;
	set_target_node_a (stack_a, stack_b);

	while (stack_a != NULL)
	{
		temp = *stack_b;
		while (temp != NULL)
		{
			if ((*stack_a)->target== temp)
			{
			(*stack_a)->cost += temp->cost;
				break ;
			}
			temp = temp->next;
		}
		(*stack_a) = (*stack_a)->next;
	}
}
void	pre_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	assign_indices(*stack_a);
	assign_indices(*stack_b);
	set_target_node_a (stack_a, stack_b);
    find_cost(*stack_a);
    find_cost(*stack_b);
    // add_cost_of_a_and_b(*stack_a, stack_b);
	//  calculate_combined_cost(stack_a, stack_b, nodes_a, nodes_b);
}

void	max_ontop(t_stack_node **stack_b)
{
	t_stack_node	*max;

	max = find_max_b(stack_b);
	assign_indices(*stack_b);
	while (max->index != 0)
	{
		if (max->median == 1)
			rb(stack_b);
		else if (max->median == 0)
			rrb(stack_b);
		assign_indices(*stack_b);
	}
}
t_stack_node 	*find_max_pointer(t_stack_node  *head)
{
	t_stack_node 	*max;

	max = head;
	while (head != NULL)
	{
		if (max->data < head->data)
			max = head;
		head = head->next;
	}
    return(max);
}
void	find_max_bb(t_stack_node  **stack_b)
{
	t_stack_node 	*max;
    // if(*stack_b == NULL)
    //     {
    //         printf("null");
    //         return;
    //     }
    //     print_stack(*stack_b);
	max = find_max_pointer(*stack_b);
	assign_indices(*stack_b);
	while (max->index != 0)
	{
		if (max->median == 1)
			rb(stack_b);
		else if (max->median == 0)
			rrb(stack_b);
		assign_indices(*stack_b);
	}
}

t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*smallest;
	t_stack_node	*current;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	current = (*stack)->next;
	smallest = *stack;
	while (current != NULL)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
	}
	free(current);
	return (smallest);
}
void sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *cheap;

    int total_a = count_nodes(*stack_a);
    int total_b = count_nodes(*stack_b);

    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while (count_nodes(*stack_a) > 0)
    {
		total_a = count_nodes(*stack_a);
        total_b = count_nodes(*stack_b);
        pre_sort(stack_a, stack_b);
		
        cheap = cheapest_node(*stack_a, *stack_b, total_a, total_b);
			if (cheap->median == 1 && cheap->target->median == 1)
				rotate_a_b(stack_a, stack_b, cheap);
            else if (cheap->median == 0 && cheap->target->median == 0)
                reverse_rotate_a_and_b(stack_a, stack_b, cheap);
			else if(cheap->median == 1 && cheap->target->median == 0)
			{
				ra(stack_a);
				rrb(stack_b);
			}
			else if (cheap->median == 0 && cheap->target->median == 1)
			{
				rra(stack_a);
				rb(stack_b);
			}
        put_node_on_top_a(stack_a, cheap);
        put_node_on_top_b(stack_b, cheap);
        pb(stack_a, stack_b);
    }
    find_max_bb(stack_b);
    // while (stack_b != NULL)
    // {
    //     pa(stack_a, stack_b);
	// 	(*stack_b) = (*stack_b)->next;
    // }
    print_stack(*stack_b);
	printf("\n");
	free_list(*stack_a);
	free_list(*stack_b);
}

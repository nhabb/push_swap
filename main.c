/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:14:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 17:14:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    error_handling(t_stack_node *stack_a)
{
    if (already_sorted(stack_a) == true)
    {
        ft_printf("sorted\n");
        return (true);
    }
    else if (find_dup(&stack_a) == true)
    {
        ft_printf("ERROR3\n");
        return (true);
    }
    return (false);
}

int main(int argc, char **argv)
{
    t_stack_node *stack_a = NULL;
    t_stack_node *stack_b = NULL;
    if (argc > 1) 
    {
        input_to_stack(argc, argv, &stack_a);
        // print_stack(stack_a);
        // printf("\n");
        if (find_dup(&stack_a) == true)
            exit(1);
        int nodes = count_nodes(stack_a);
        // printf("%d\n",nodes);
        error_handling(stack_a);
        if (nodes == 3)
        {
            sort_three(&stack_a);
        //     print_stack(stack_a);
        //     print_stack(stack_b);
        }
        else
        {
            sort(&stack_a,&stack_b);
        }
        // pr
    }
    free_list(stack_a);
    // t_stack_node *current = stack_a;
    // while (current)
    // {
    //     printf("%d\n", findPos(current, &stack_a));
    //     current = current -> next;
    // }
    return 0;
}

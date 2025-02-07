
#include "push_swap.h"

void	rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheap)
{
	while (cheap->index != 0 && cheap->target->index != 0)
	{
		rr(stack_a, stack_b);
		assign_indices(*stack_a);
		assign_indices(*stack_b);
	}
}

void	reverse_rotate_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (cheapest->index != 0 && cheapest->target->index != 0)
	{
		rrr(stack_a, stack_b);
		assign_indices(*stack_a);
		assign_indices(*stack_b);
	}
}



void	put_node_on_top_a(t_stack_node **stack_a, t_stack_node *cheapest)
{
	while (cheapest->index != 0)
	{
		if (cheapest->median == 1)
		{
			ra(stack_a);
		}
		else
		{
			rra(stack_a);
		}
		assign_indices(*stack_a);
	}
}

void	put_node_on_top_b(t_stack_node **stack_b, t_stack_node *cheapest)
{
	while (cheapest->target->index != 0)
	{
		if (cheapest->target->median == 1)
		{
			rb(stack_b);
		}
		else
			rrb(stack_b);
		assign_indices(*stack_b);
	}
}

void	reverse_rotate_a_and_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (cheapest->index != 0 && cheapest->target->index !=0)
	{
		rrr(stack_a, stack_b);
		assign_indices(*stack_a);
		assign_indices(*stack_b);
	}
}
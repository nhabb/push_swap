/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:16:49 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 11:16:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct list_node
{
	long long int					data;
	int					index;
	int					cost;
	int					median;
	long long int					number;
	struct list_node	*next;
	struct list_node	*prev;
	struct list_node	*target;
}						t_stack_node;
void	find_cost(t_stack_node *head);
void	add_cost_of_a_and_b(t_stack_node*stack_a, t_stack_node **stack_b);
int				count_nodes(t_stack_node *stack_a);
bool			new_atoi(const char *nptr, long long int *ftatoi);
int 			calculate_rotation_cost(int index, int total_nodes);
int 			calculate_combined_cost(t_stack_node *node_a, t_stack_node *node_b, 
						int total_nodes_a, int total_nodes_b);
int 			max_cost(int cost1, int cost2);
int findPos(t_stack_node *node,t_stack_node **stack_a);
void			print_stack(t_stack_node *head);
void			sa(t_stack_node	**stack_a);
void			sb(t_stack_node	**stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void			print_ops(t_stack_node *stack_a);
void			free_list(t_stack_node *stack_a);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
bool			input_to_stack(int argc, char **argv, t_stack_node **stack_a);
void			correct_order(t_stack_node	**stack_a, long long int input);
void			push_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_three_helper(t_stack_node **stack_a, long long int first,
			long long int second,long long int third);
void			set_target_node_a(t_stack_node *s, t_stack_node *node);
void			free_main(t_stack_node *stack_a, t_stack_node *stack_b);
void 			assign_indices(t_stack_node *stack);
void			quoted_args(const char *str);
void			rotate_a_b(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheap);
void			reverse_rotate_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest);
void			reverse_rotate_a_and_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest);
void			put_node_on_top_a(t_stack_node **stack_a, t_stack_node *cheapest);
void			put_node_on_top_b(t_stack_node **stack_b, t_stack_node *cheapest);
bool			error_handling(t_stack_node *stack_a);
void			many_args_error(int *data, bool error);
void			check_av_helper(char **av);
void			many_arguments(t_stack_node **stack_a, char **argv, int argc);
void			return_pointer_to_first(t_stack_node **node);
void			exit_sort(int *data, t_stack_node **stack_a);
void sort(t_stack_node **stack_a, t_stack_node **stack_b);
bool			find_dup(t_stack_node **head);
bool			strcmp_max(t_stack_node *max, t_stack_node *num);
bool			already_sorted(t_stack_node *head);
bool			is_valid_number(const char *str, long *res);
bool			valid_bounds(int argc, char **argv, t_stack_node **stack_a);
bool			numerical_param(char *arg);
bool			extra_cases(char *arg);
t_stack_node			*create_new_node(int number);
t_stack_node	*create_list(int *input, int count, int flag);
t_stack_node	*sort_three(t_stack_node **stack_a);
t_stack_node	*find_max_b(t_stack_node **stack_b);
t_stack_node	*find_min_b(t_stack_node **stack_b);
t_stack_node	*cheapest_node(t_stack_node *stack_a, t_stack_node *stack_b,
							int total_a, int total_b);

# endif
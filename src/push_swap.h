/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:47:56 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 21:58:07 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack_node
{
	int					number;
	int					median;
	int					cost;
	int					position;
	struct t_stack_node	*next;
	struct t_stack_node	*prev;
	struct t_stack_node	*target;
}					t_stack_node;
typedef struct t_input
{
	int				input_count;
}					t_input;
void				sort_two(t_stack_node **a);
void				check_negative(char *argv);
bool				check_str(char **av);
void				check_space(char *argv);
t_stack_node		*create_node(int number);
t_stack_node		*create_list(int *input, int count, int flag);
void				combined_cost(t_stack_node *stack_a,
						t_stack_node **stack_b);
int					count_nodes(t_stack_node *temp);
bool				is_numeric(char **data, int flag);
void				calculate_cost(t_stack_node *head);
void				free_2d_array(char **data);
void				quoted_arg_helper(t_input **input, t_stack_node **stack_a,
						bool indicator, int **data);
void				quoted_arg_helper1(t_input **input, t_stack_node **stack_a,
						bool indicator, int **data);
void				set_target_of_a(t_stack_node *stack_a,
						t_stack_node *stack_b);
void				free_list(t_stack_node *node);
void				return_to_top(t_stack_node **node);
void				print_stack_node(t_stack_node *head);
void				free_2d_array(char **data);
void				swap(t_stack_node **head);
void				rotate(t_stack_node **head);
void				reverse_rotate(t_stack_node **head);
void				push(t_stack_node **send_form, t_stack_node **send_to);
t_stack_node		*cheapest_node(t_stack_node *head);
bool				split_argument(char *argv, t_input **input, int **data);
bool				already_sorted(t_stack_node *head);
bool				parse_input(char **input, int count,
						int **data);
int					new_atoi(char *str, int *ftatoi);
int					char_is_separator(char c, char *charset);
bool				check_duplicate(t_stack_node *head);
void				assign_indices(t_stack_node *head);
t_stack_node		*find_max(t_stack_node *head);
void				mini_sort(t_stack_node **stack_a, t_stack_node **stack_b);
bool				already_sorted(t_stack_node *head);
bool				check_duplicate(t_stack_node *head);
bool				is_numeric(char **data, int flag);
void				quoted_arg(char *argv, t_stack_node **stack_a);
char				**ft_split(char *str, char *charset);
void				sa(t_stack_node **head, int flag);
void				pa(t_stack_node **head_a, t_stack_node **head_b);
void				ra(t_stack_node **head, int flag);
void				rra(t_stack_node **head, int flag);
void				rrb(t_stack_node **head, int flag);
void				rb(t_stack_node **head, int flag);
void				sb(t_stack_node **head, int flag);
void				non_quoted_args(int *data, bool error);
void				non_quoted_arg(t_stack_node **stack_a,
						char **argv, int argc);
void				pb(t_stack_node **head_a, t_stack_node **head_b);
void				rr(t_stack_node **head_a, t_stack_node **head_b);
void				rrr(t_stack_node **head_a, t_stack_node **head_b);
void				sort(t_stack_node *stack_a,
						t_stack_node *stack_b);
void				sort_max(t_stack_node **stack_b);
void				pre_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void				rotate_a_and_b(t_stack_node **stack_a,
						t_stack_node **stack_b, t_stack_node *cheap);
void				reverse_rotate_a_and_b(t_stack_node **stack_a,
						t_stack_node **stack_b,
						t_stack_node *cheapest);
void				put_node_on_top_a(t_stack_node **stack_a,
						t_stack_node *cheapest);
void				put_node_on_top_b(t_stack_node **stack_b,
						t_stack_node *cheapest);
void				free_and_exit_1(t_input *input, int *data,
						t_stack_node **stack_a);
void				free_and_exit_if_sorted(int *data, t_stack_node **stack_a);
void				sort_three(t_stack_node **stack);
void				sort_four(t_stack_node **a, t_stack_node **b);
void				sort_five(t_stack_node **a, t_stack_node **b);
#endif

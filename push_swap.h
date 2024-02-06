/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:15 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/06 19:17:10 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	int						push_cost;
	bool					below_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*previous;
}							t_stack_node;

typedef struct s_struct_tree
{
	int						data;
	struct s_struct_tree	*left;
	struct s_struct_tree	*right;
}							t_binary_tree;

bool						ft_parse_arguments(char *argv[],
								t_stack_node **stack);
void						ft_free_array(char *argv[]);

// Functions for handling errors
void						ft_no_arguments(void);
void						ft_error_in_split(void);
bool						ft_integer_overflow(void);
void						ft_invalid_arguments(char *argv[], bool malloc);

// Functions for binary tree check
t_binary_tree				*ft_add_tree_node(int value);
t_binary_tree				*ft_check_duplicate(t_binary_tree **root,
								int value);
void						free_tree(t_binary_tree *root);

// Functions for stacks
t_stack_node				*ft_add_to_stack(t_stack_node **stack, int value);
void						ft_free_stack(t_stack_node **stack);
unsigned int				ft_stack_length(t_stack_node **head);
t_stack_node				*ft_last_node(t_stack_node **head);
void						ft_sort_two(t_stack_node **a);
void						ft_sort_three(t_stack_node **a);
void						ft_mechanical_turk(t_stack_node **a,
								t_stack_node **b, unsigned int counter);
bool						ft_check_sorted(t_stack_node **a);
void						ft_prepare_stack_a(t_stack_node **a,
								t_stack_node **b);

// Functions for allowed operations
void						swap_a(t_stack_node **a, bool only_a);
void						push_a(t_stack_node **stack_a,
								t_stack_node **stack_b);
void						rotate_a(t_stack_node **a, bool only_a);
void						reverse_rotate_a(t_stack_node **a, bool only_a);
void						swap_b(t_stack_node **b, bool only_b);
void						push_b(t_stack_node **stack_a,
								t_stack_node **stack_b);
void						rotate_b(t_stack_node **b, bool only_b);
void						reverse_rotate_b(t_stack_node **b, bool only_b);
void						swap_s(t_stack_node **a, t_stack_node **b);
void						rotate_r(t_stack_node **a, t_stack_node **b);
void						reverse_rotate_r(t_stack_node **a,
								t_stack_node **b);
#endif

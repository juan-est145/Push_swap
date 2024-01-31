/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:15 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/31 19:03:41 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}						t_stack_node;

bool					ft_parse_arguments(char *argv[], t_stack_node **stack);
t_stack_node			*ft_add_to_stack(t_stack_node **stack, int value);

// Functions for handling errors
void					ft_no_arguments(void);
void					ft_error_in_split(void);
bool					ft_integer_overflow(void);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 17:09:13 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	rotate_cheapest_on_top(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest_node);
static void	reverse_rotate_cheapest_on_top(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest_node);

void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_return_cheapest_node(a);
	if (cheapest_node->below_median == true
		&& cheapest_node->target_node->below_median == true)
		rotate_cheapest_on_top(a, b, cheapest_node);
	else if (cheapest_node->below_median == false
		&& cheapest_node->target_node->below_median == false)
		reverse_rotate_cheapest_on_top(a, b, cheapest_node);
	check_correct_heads(a, cheapest_node, 'a');
	check_correct_heads(b, cheapest_node->target_node, 'b');
	push_b(a, b);
}

static void	rotate_cheapest_on_top(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rotate_r(a, b);
	ft_update_index(a);
	ft_update_index(b);
}

static void	reverse_rotate_cheapest_on_top(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		reverse_rotate_r(a, b);
	ft_update_index(a);
	ft_update_index(b);
}

void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	check_correct_heads(a, (*b)->target_node, 'a');
	push_a(a, b);
}


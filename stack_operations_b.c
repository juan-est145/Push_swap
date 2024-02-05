/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:23:56 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/05 17:51:11 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap_b(t_stack_node **b, bool only_b)
{
	int	temp;

	temp = 0;
	if (*b != NULL && (*b)->next != NULL)
	{
		temp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = temp;
		if (only_b == true)
			ft_printf("sb\n");
	}
}

void	push_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	temp = NULL;
	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a != NULL)
		{
			(*stack_a)->previous = NULL;
			temp->next = NULL;
		}
		if (*stack_b != NULL)
		{
			temp->next = *stack_b;
			(*stack_b)->previous = temp;
		}
		*stack_b = temp;
		ft_printf("pb\n");
	}
}

void	rotate_b(t_stack_node **b, bool only_b)
{
	t_stack_node	*last_node;

	last_node = NULL;
	if (*b != NULL && (*b)->next != NULL)
	{
		last_node = ft_last_node(b);
		last_node->next = *b;
		*b = (*b)->next;
		(*b)->previous = NULL;
		last_node->next->previous = last_node;
		last_node->next->next = NULL;
		if (only_b == true)
			ft_printf("rb\n");
	}
}

void	reverse_rotate_b(t_stack_node **b, bool only_b)
{
	t_stack_node	*last_node;

	last_node = NULL;
	if (*b != NULL && (*b)->next != NULL)
	{
		last_node = ft_last_node(b);
		last_node->previous->next = NULL;
		last_node->next = *b;
		last_node->previous = NULL;
		(*b)->previous = last_node;
		*b = last_node;
		if (only_b == true)
			ft_printf("rrb\n");
	}
}

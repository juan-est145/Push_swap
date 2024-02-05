/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:01:31 by juan              #+#    #+#             */
/*   Updated: 2024/02/05 15:46:28 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap_a(t_stack_node **a)
{
	int	temp;

	temp = 0;
	if (*a != NULL && (*a)->next != NULL)
	{
		temp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = temp;
		ft_printf("sa\n");
	}
}

void	rotate_a(t_stack_node **a)
{
	t_stack_node	*last_node;

	last_node = NULL;
	if (*a != NULL && (*a)->next != NULL)
	{
		last_node = ft_last_node(a);
		last_node->next = *a;
		*a = (*a)->next;
		(*a)->previous = NULL;
		last_node->next->previous = last_node;
		last_node->next->next = NULL;
		ft_printf("ra\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:01:31 by juan              #+#    #+#             */
/*   Updated: 2024/02/04 16:25:45 by juan             ###   ########.fr       */
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
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:01:31 by juan              #+#    #+#             */
/*   Updated: 2024/02/03 11:10:22 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:06 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/31 19:23:30 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void		ft_malloc_failure(t_stack_node **stack);

t_stack_node	*ft_add_to_stack(t_stack_node **stack, int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
	{
		ft_malloc_failure(stack);
		ft_printf("Error allocating memory to stash node, exiting program\n");
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	if (*stack != NULL)
	{
		(*stack)->previous = node;
		node->next = (*stack);
		*stack = node;
	}
	return (node);
}

static void	ft_malloc_failure(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (*stack != NULL)
	{
		while (*stack != NULL)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
}

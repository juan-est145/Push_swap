/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:06 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 18:51:36 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static void		ft_malloc_failure(t_stack_node **stack);
static void		ft_queue(t_stack_node **head, t_stack_node *node);

t_stack_node	*ft_add_to_stack(t_stack_node **stack, int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
	{
		ft_malloc_failure(stack);
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	if (*stack != NULL)
		ft_queue(stack, node);
	else
		*stack = node;
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
	ft_printf("Error allocating memory to stash node, exiting program\n");
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	temp = NULL;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

static void	ft_queue(t_stack_node **head, t_stack_node *node)
{
	t_stack_node	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	node->previous = temp;
	temp->next = node;
}

unsigned int	ft_stack_length(t_stack_node **head)
{
	unsigned int	counter;
	t_stack_node	*temp;

	counter = 0;
	temp = *head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

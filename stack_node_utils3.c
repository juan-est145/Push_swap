/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:00:58 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 17:22:00 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_correct_heads(t_stack_node **head, t_stack_node *cheapest_node,
		char type_of_stack)
{
	while (*head != cheapest_node)
	{
		if (type_of_stack == 'a')
		{
			if (cheapest_node->below_median == true)
				rotate_a(head, true);
			else
				reverse_rotate_a(head, true);
		}
		else if (type_of_stack == 'b')
		{
			if (cheapest_node->below_median == true)
				rotate_b(head, true);
			else
				reverse_rotate_b(head, true);
		}
	}
}

void	ft_place_min_a_on_head(t_stack_node **a)
{
	t_stack_node	*lowest_value_node;

	lowest_value_node = ft_find_lowest_value_node(a);
	while ((*a)->value != lowest_value_node->value)
	{
		if (lowest_value_node->below_median == true)
			rotate_a(a, true);
		else
			reverse_rotate_a(a, true);
	}
}

t_stack_node	*ft_find_lowest_value_node(t_stack_node **head)
{
	t_stack_node	*temp;
	int				lowest_value;
	t_stack_node	*return_node;

	if (*head == NULL)
		return (NULL);
	temp = *head;
	lowest_value = 2147483647;
	return_node = NULL;
	while (temp != NULL)
	{
		if (temp->value < lowest_value)
		{
			lowest_value = temp->value;
			return_node = temp;
		}
		temp = temp->next;
	}
	return (return_node);
}

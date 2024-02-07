/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:58 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 16:30:18 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void			find_targets_b(t_stack_node **a, t_stack_node **b);
static t_stack_node	*ft_find_lowest_value_node(t_stack_node **head);

void	ft_prepare_stack_b(t_stack_node **a, t_stack_node **b)
{
	ft_update_index(a);
	ft_update_index(b);
	find_targets_b(a, b);
}

static void	find_targets_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	bool			found_highest_best;
	int				highest_best;

	temp_b = *b;
	while (temp_b != NULL)
	{
		highest_best = 2147483647;
		temp_a = *a;
		found_highest_best = false;
		while (temp_a != NULL)
		{
			if (temp_a->value > temp_b->value && temp_a->value < highest_best)
			{
				highest_best = temp_a->value;
				temp_b->target_node = temp_a;
				found_highest_best = true;
			}
			temp_a = temp_a->next;
		}
		if (found_highest_best == false)
			temp_b->target_node = ft_find_lowest_value_node(b);
		temp_b = temp_b->next;
	}
}

static t_stack_node	*ft_find_lowest_value_node(t_stack_node **head)
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

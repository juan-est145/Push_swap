/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:23:03 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 13:11:00 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	ft_update_index(t_stack_node **head);
static void	find_targets_a(t_stack_node **a, t_stack_node **b);
static void	calculate_move_cost_a(t_stack_node **a, t_stack_node **b);
static void	find_cheapest_push_a(t_stack_node **head);

void	ft_prepare_stack_a(t_stack_node **a, t_stack_node **b)
{
	ft_update_index(a);
	ft_update_index(b);
	find_targets_a(a, b);
	calculate_move_cost_a(a, b);
	find_cheapest_push_a(a);
}

static void	ft_update_index(t_stack_node **head)
{
	unsigned int	i;
	unsigned int	median;
	t_stack_node	*temp;

	if (*head == NULL)
		return ;
	median = ft_stack_length(head) / 2;
	i = 0;
	temp = *head;
	while (temp != NULL)
	{
		temp->index = i;
		if (i <= median)
			temp->below_median = true;
		else if (i > median)
			temp->below_median = false;
		temp = temp->next;
		i++;
	}
}

static void	find_targets_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	bool			found_lowest_best;
	int				lowest_best;

	temp_a = *a;
	while (temp_a != NULL)
	{
		lowest_best = -2147483648;
		temp_b = *b;
		found_lowest_best = false;
		while (temp_b != NULL)
		{
			if (temp_a->value > temp_b->value && temp_b->value > lowest_best)
			{
				lowest_best = temp_b->value;
				temp_a->target_node = temp_b;
				found_lowest_best = true;
			}
			temp_b = temp_b->next;
		}
		if (found_lowest_best == false)
			temp_a->target_node = ft_find_highest_value_node(b);
		temp_a = temp_a->next;
	}
}

static void	calculate_move_cost_a(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*temp;

	len_a = ft_stack_length(a);
	len_b = ft_stack_length(b);
	temp = *a;
	while (temp != NULL)
	{
		temp->push_cost = temp->index;
		if (temp->below_median == false)
			temp->push_cost = len_a - (temp->index);
		if (temp->target_node->below_median == true)
			temp->push_cost += temp->target_node->index;
		else
			temp->push_cost += len_b - (temp->target_node->index);
		temp = temp->next;
	}
}

static void	find_cheapest_push_a(t_stack_node **head)
{
	t_stack_node	*temp;
	t_stack_node	*cheapest_node;
	int				cheapest_value;

	cheapest_node = NULL;
	cheapest_value = 2147483647;
	temp = *head;
	while (temp != NULL)
	{
		if (temp->push_cost < cheapest_value)
		{
			cheapest_value = temp->push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->cheapest = true;
}

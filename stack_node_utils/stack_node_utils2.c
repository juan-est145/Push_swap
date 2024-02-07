/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:23:45 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 18:51:44 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

t_stack_node	*ft_last_node(t_stack_node **head)
{
	t_stack_node	*temp;

	temp = *head;
	if (*head == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

bool	ft_check_sorted(t_stack_node **a)
{
	t_stack_node	*temp;

	if (*a == NULL)
		return (true);
	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

t_stack_node	*ft_find_highest_value_node(t_stack_node **head)
{
	t_stack_node	*temp;
	int				highest_value;
	t_stack_node	*return_node;

	if (*head == NULL)
		return (NULL);
	temp = *head;
	highest_value = -2147483648;
	return_node = NULL;
	while (temp != NULL)
	{
		if (temp->value > highest_value)
		{
			highest_value = temp->value;
			return_node = temp;
		}
		temp = temp->next;
	}
	return (return_node);
}

t_stack_node	*ft_return_cheapest_node(t_stack_node **head)
{
	t_stack_node	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->cheapest == true)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_update_index(t_stack_node **head)
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

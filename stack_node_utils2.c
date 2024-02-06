/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:23:45 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:52 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

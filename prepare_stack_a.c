/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:23:03 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/06 19:20:40 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	ft_update_index(t_stack_node **head);

void	ft_prepare_stack_a(t_stack_node **a, t_stack_node **b)
{
	ft_update_index(a);
	ft_update_index(b);
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

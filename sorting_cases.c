/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:56:13 by juan              #+#    #+#             */
/*   Updated: 2024/02/05 18:57:24 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sort_two(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(a, true);
}

// The first if is for the case that max value is in the tail 
// and min value is at the middle.

// The second if is for the case that max value is at head and min value is
//at the middle

//The third if is for the case that max value is at the middle and min value
// is at the head

//The fourth if is for the case that max value is at the middle and min value
//is at the tail

//The fith if is for the case that max value is at head and min value
// is on the tail

// If the stack is already sorted, (min value at head and max value at tail)
// the function does nothing

void	ft_sort_three(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		swap_a(a, true);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		rotate_a(a, true);
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		swap_a(a, true);
		rotate_a(a, true);
	}
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		reverse_rotate_a(a, true);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		swap_a(a, true);
		reverse_rotate_a(a, true);
	}
}

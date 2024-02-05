/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_combined.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:45:21 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/05 17:59:03 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap_s(t_stack_node **a, t_stack_node **b)
{
	swap_a(a, false);
	swap_b(b, false);
	ft_printf("ss\n");
}

void	rotate_r(t_stack_node **a, t_stack_node **b)
{
	rotate_a(a, false);
	rotate_b(b, false);
	ft_printf("rr\n");
}

void	reverse_rotate_r(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_a(a, false);
	reverse_rotate_b(b, false);
	ft_printf("rrr\n");
}

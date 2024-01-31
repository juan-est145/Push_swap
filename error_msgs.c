/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:41 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/31 18:34:45 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_no_arguments(void)
{
	ft_printf("Error, no arguments provided, exiting the program\n");
	exit(1);
}

void	ft_error_in_split(void)
{
	ft_printf("Error, malloc in split failed, exiting program\n");
	exit(1);
}

bool	ft_integer_overflow(void)
{
	ft_printf("Integer overflow, exiting program\n");
	return (false);
}

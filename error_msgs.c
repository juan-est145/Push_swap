/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:41 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 19:13:18 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_no_arguments(void)
{
	exit(1);
}

void	ft_error_in_split(void)
{
	ft_printf("Error, malloc in split failed, exiting program\n");
	exit(1);
}

void	ft_invalid_arguments(char *argv[], bool malloc)
{
	ft_printf("Error\n");
	if (malloc == true)
		ft_free_array(argv);
	exit(1);
}

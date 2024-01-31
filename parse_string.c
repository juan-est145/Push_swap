/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:52:37 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/31 16:39:59 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Need to check no duplicate numbers
// 0 5 2 3 5 -5 Valid input
// "4 5 6 8 9" 2 -2 +9 Invalid input
// 2.4 2 4 1 4 5 Invalid Input

#include "libft/libft.h"
#include "push_swap.h"

bool	ft_parse_arguments(char *argv[])
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	while (argv[i] != NULL)
	{
		if (!(argv[i][0] >= '0' && argv[i][0] <= '9') && argv[i][0] != '+'
			&& argv[i][0] != '-')
			return (false);
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (false);
			j++;
		}
		i++;
		j = 1;
	}
	return (true);
}

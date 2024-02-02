/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:31:25 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/02 17:37:51 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void ft_leaks()
{
	system("leaks -q Push_Swap");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks);
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		ft_no_arguments();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			ft_error_in_split();
		if (ft_parse_arguments(argv, &a) == false)
			ft_invalid_arguments(argv, true);
		free(argv);
	}
	else
		if (ft_parse_arguments(argv + 1, &a) == false)
			ft_invalid_arguments(argv, false);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:31:25 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/03 11:16:05 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q Push_Swap");
}

// TO DO: Change the creation of the stack so that the first argument 
//becomes the one on top

// atexit(ft_leaks);
int	main(int argc, char *argv[])
{
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
		ft_printf("%i\n", b->value);
		ft_free_array(argv);
	}
	else if (ft_parse_arguments(argv + 1, &a) == false)
		ft_invalid_arguments(argv, false);
	return (0);
}

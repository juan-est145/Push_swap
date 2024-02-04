/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:31:25 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/04 11:53:48 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q Push_Swap");
}

//atexit(ft_leaks);

static void	ft_process_stacks(t_stack_node **a, t_stack_node **b);

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	atexit(ft_leaks);  //Erase later
	if (argc < 2 || argv[1][0] == '\0')
		ft_no_arguments();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			ft_error_in_split();
		if (ft_parse_arguments(argv, &a) == false)
			ft_invalid_arguments(argv, true);
		ft_free_array(argv);
	}
	else if (ft_parse_arguments(argv + 1, &a) == false)
		ft_invalid_arguments(argv, false);
	ft_process_stacks(&a, &b);
	return (0);
}

static void	ft_process_stacks(t_stack_node **a, t_stack_node **b)
{
	unsigned int	counter;

	(void)b; //Erase later
	counter = ft_stack_length(a);
	ft_free_stack(a);
}

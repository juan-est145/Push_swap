/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:31:25 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/31 16:34:15 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2 || argv[1][0] == '\0')
		ft_no_arguments();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			ft_error_in_split();
		ft_parse_arguments(argv);
		free(argv);
	}
	else
		ft_parse_arguments(argv + 1);
	return (0);
}

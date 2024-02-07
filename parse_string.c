/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:52:37 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/07 19:11:46 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Need to check no duplicate numbers

#include "libft/libft.h"
#include "push_swap.h"

static long	ft_atoi_long(const char *str);
static bool	ft_check_validity(char *argv[]);
static int	ft_atoi_symbols(int *i, char *str);

bool	ft_parse_arguments(char *argv[], t_stack_node **stack)
{
	long			number;
	t_binary_tree	*duplicates;

	duplicates = NULL;
	if (ft_check_validity(argv) == true)
	{
		while (*argv != NULL)
		{
			number = ft_atoi_long(*argv);
			if (number > 2147483647 || number < -2147483648)
				return (free_tree(duplicates), ft_free_stack(stack),
					false);
			if (ft_add_to_stack(stack, (int)number) == NULL)
				return (free_tree(duplicates), ft_free_stack(stack), false);
			if (ft_check_duplicate(&duplicates, (int)number) == NULL)
				return (free_tree(duplicates), ft_free_stack(stack), false);
			argv++;
		}
		return (free_tree(duplicates), true);
	}
	return (false);
}

static bool	ft_check_validity(char *argv[])
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

static long	ft_atoi_long(const char *str)
{
	int		i;
	long	result;
	int		minus_operator;
	char	*string;

	i = 0;
	result = 0;
	string = (char *)str;
	minus_operator = ft_atoi_symbols(&i, string);
	while (string[i] != '\0')
	{
		if (string[i] >= '0' && string[i] <= '9')
			result = (result * 10) + (str[i] - 48);
		else if (!(string[i] >= '0' && string[i] <= '9'))
			return (result *= minus_operator);
		i++;
	}
	return (result *= minus_operator);
}

static int	ft_atoi_symbols(int *i, char *str)
{
	int	minus_operator;

	minus_operator = 1;
	if (str[0] == '+')
		(*i)++;
	else if (str[0] == '-')
	{
		minus_operator *= -1;
		(*i)++;
	}
	return (minus_operator);
}

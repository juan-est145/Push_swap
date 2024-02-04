/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:55:17 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/04 11:40:48 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_binary_tree	*ft_add_tree_node(int value)
{
	t_binary_tree	*new_node;

	new_node = (t_binary_tree *)malloc(sizeof(t_binary_tree));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = value;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}

t_binary_tree	*ft_check_duplicate(t_binary_tree **root, int value)
{
	if (*root == NULL)
	{
		*root = ft_add_tree_node(value);
		return (*root);
	}
	if ((*root)->data < value)
		return (ft_check_duplicate(&(*root)->right, value));
	else if ((*root)->data > value)
		return (ft_check_duplicate(&(*root)->left, value));
	else if ((*root)->data == value)
		return (NULL);
	return (NULL);
}

void	free_tree(t_binary_tree *root)
{
	if (root == NULL)
	{
		return ;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

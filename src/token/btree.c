/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:35:16 by truello           #+#    #+#             */
/*   Updated: 2024/03/18 16:02:18 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*new_leaf(void *val)
{
	t_btree	*res;

	res->val = val;
	res->left = NULL;
	res->right = NULL;
	return (res);
}

void	clear_tree(t_btree *tree)
{
	free(tree->val);
	if (tree->left != NULL)
		clear_tree(tree->left);
	if (tree->right != NULL)
		clear_tree(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		free(tree);
}

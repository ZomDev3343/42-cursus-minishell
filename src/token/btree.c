/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:35:16 by truello           #+#    #+#             */
/*   Updated: 2024/03/19 16:53:36 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*new_leaf(void *val)
{
	t_btree	*res;

	res = (t_btree *) ft_calloc(1, sizeof(t_btree));
	res->val = val;
	res->left = NULL;
	res->right = NULL;
	return (res);
}

void	clear_tree(t_btree *tree)
{
	free(tree->val);
	if (tree->left)
		clear_tree(tree->left);
	if (tree->right)
		clear_tree(tree->right);
	if (!tree->left && !tree->right)
		free(tree);
}

int	put_after(t_btree *tree, t_btree *leaf)
{
	t_btree	*last_leaf;

	if (!tree)
		return (FALSE);
	last_leaf = tree->right;
	while (last_leaf->right)
		last_leaf = last_leaf->right;
	last_leaf->right = leaf;
	return (TRUE);
}

int	put_before(t_btree *tree, t_btree *leaf)
{
	t_btree	*first_leaf;

	if (!tree)
		return (FALSE);
	first_leaf = tree->left;
	while (first_leaf->left)
		first_leaf = first_leaf->left;
	first_leaf->left = leaf;
	return (TRUE);
}

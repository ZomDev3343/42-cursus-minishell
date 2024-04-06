/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:35:16 by truello           #+#    #+#             */
/*   Updated: 2024/04/06 18:19:46 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*newleaf(t_token *token)
{
	t_btree	*res;

	res = (t_btree *) ft_calloc(1, sizeof(t_btree));
	if (!res)
		return (NULL);
	res->token = token;
	res->left = NULL;
	res->right = NULL;
	return (res);
}

void	free_tree(t_btree *tree)
{
	if (!tree)
		return ;
	free_token(tree->token);
	if (tree->left)
		free_tree(tree->left);
	if (tree->right)
		free_tree(tree->right);
	free(tree);
}

int	put_after(t_btree *tree, t_btree *leaf)
{
	t_btree	*last_leaf;

	if (!tree)
		return (FALSE);
	last_leaf = get_last_leaf(tree);
	last_leaf->right = leaf;
	return (TRUE);
}

int	put_before(t_btree *tree, t_btree *leaf)
{
	t_btree	*first_leaf;

	if (!tree)
		return (FALSE);
	first_leaf = get_first_leaf(tree);
	first_leaf->left = leaf;
	return (TRUE);
}

t_btree	*get_first_leaf(t_btree *tree)
{
	if (!tree)
		return (NULL);
	while (tree->left)
		tree = tree->left;
	return (tree);
}

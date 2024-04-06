/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:43:54 by tohma             #+#    #+#             */
/*   Updated: 2024/04/06 18:28:44 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*get_last_leaf(t_btree *tree)
{
	if (!tree)
		return (NULL);
	while (tree->right)
		tree = tree->right;
	return (tree);
}

void	print_tree(t_btree *tree, int floor)
{
	int	i;

	i = -1;
	if (!tree)
		return ;
	while (++i < floor)
		printf("-");
	printf("'%s' [%d]\n", tree->token->data, tree->token->flag);
	print_tree(tree->left, floor + 1);
	print_tree(tree->right, floor + 1);
}

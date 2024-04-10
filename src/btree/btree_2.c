/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:43:54 by tohma             #+#    #+#             */
/*   Updated: 2024/04/09 16:48:39 by truello          ###   ########.fr       */
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

int	is_tree_correct(t_btree *tree)
{
	t_btree	*tmp;

	tmp = tree;
	while (tmp)
	{
		if (tmp->token->flag == E_PIPE)
			if (!tmp->left || tmp->left->token->flag != E_CMD
				|| !tmp->right || tmp->right->token->flag != E_CMD)
				return (FALSE);
		tmp = tmp->right;
	}
	return (TRUE);
}

void	put_command(t_btree *tree, char *cmd)
{
	t_btree	*tmp;

	if (!tree->left)
		tree->left = newleaf(newtoken(cmd, E_CMD));
	if (!tree->right)
		tree->right = newleaf(newtoken(cmd, E_CMD));
	tmp = tree->right;
	while (tmp->right)
	{
		if (!tmp->left)
			tmp->left = newleaf(newtoken(cmd, E_CMD));
		else if (!tmp->right)
			tmp->right = newleaf(newtoken(cmd, E_CMD));
		else
		{
			tmp = tmp->right;
			continue ;
		}
		return ;
	}
}

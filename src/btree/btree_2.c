/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:43:54 by tohma             #+#    #+#             */
/*   Updated: 2024/03/26 16:12:53 by tohma            ###   ########.fr       */
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

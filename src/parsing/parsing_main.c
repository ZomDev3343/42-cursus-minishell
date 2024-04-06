/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:11:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/06 18:17:46 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*parse_exec_tree(t_minishell *minfos, t_token_lst *tlst)
{
	t_btree	*tree;

	tree = NULL;
	if (parse_minfos(minfos, tlst))
	{
		put_pipes_in_tree(&tree, tlst);
		print_tree(tree, 0);
		printf("orhgihrhge\n");
	}
	return (tree);
}

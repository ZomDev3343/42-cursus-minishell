/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:11:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/09 16:22:22 by truello          ###   ########.fr       */
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
		parse_commands(minfos, tree, tlst);
		printf("Commands Parsed!\n");
		print_tree(tree, 0);
		/*if (is_tree_correct(tree))
			exec_tree(tree);*/
	}
	return (tree);
}

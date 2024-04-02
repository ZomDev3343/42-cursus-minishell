/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:11:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/02 16:35:27 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	parse_pipes(t_minishell *minfos, t_token_lst *tlst)
// {

// }

t_btree	*parse_exec_tree(t_minishell *minfos, t_token_lst *tlst)
{
	t_btree	*tree;

	tree = (t_btree *) ft_calloc(1, sizeof(t_btree));
	if (!tree)
		return (NULL);
	if (parse_minfos(minfos, tlst))
		printf("orhgihrhge\n");
	return (tree);
}

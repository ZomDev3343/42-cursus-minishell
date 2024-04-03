/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/04/03 15:42:10 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char		*prompt;
	t_token_lst	*tlst;
	t_minishell	*minfos;
	t_btree		*tree;

	minfos = init_minishell();
	prompt = readline("minishell > ");
	while (prompt[0] != '\0')
	{
		tlst = tokenize(prompt);
		print_token_list(tlst);
		tree = parse_exec_tree(minfos, tlst);
		free_token_lst(&tlst);
		clear_minfos_rfiles(minfos);
		free_tree(tree);
		free(prompt);
		prompt = readline("minishell > ");
	}
	free_minfos(minfos);
	free(prompt);
	return (0);
}

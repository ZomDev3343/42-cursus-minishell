/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/04/03 14:30:50 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char		*prompt;
	t_token_lst	*tlst;
	t_minishell	*minfos;

	minfos = init_minishell();
	prompt = readline("minishell > ");
	while (prompt[0] != '\0')
	{
		tlst = tokenize(prompt);
		print_token_list(tlst);
		parse_exec_tree(minfos, tlst);
		free_redir_files(&(minfos->input_files));
		free_redir_files(&(minfos->output_files));
		free_token_lst(&tlst);
		free(prompt);
		prompt = readline("minishell > ");
	}
	free(prompt);
	return (0);
}

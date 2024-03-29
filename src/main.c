/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/03/29 18:23:39 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char		*prompt;
	t_token_lst	*tlst;

	prompt = readline("minishell > ");
	while (prompt[0] != '\0')
	{
		tlst = tokenize(prompt);
		print_token_list(tlst);
		free_token_lst(&tlst);
		//parse_exec_tree(prompt);
		free(prompt);
		prompt = readline("minishell > ");
	}
	free(prompt);
	return (0);
}

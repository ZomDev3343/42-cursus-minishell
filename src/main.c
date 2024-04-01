/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/04/01 16:04:01 by truello          ###   ########.fr       */
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
		free(prompt);
		prompt = readline("minishell > ");
	}
	free(prompt);
	return (0);
}

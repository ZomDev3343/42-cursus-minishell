/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/03/26 13:50:20 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char	*prompt;

	prompt = readline("minishell > ");
	while (prompt[0] != '\0')
	{
		parse_exec_tree(prompt);
		free(prompt);
		prompt = readline("minishell > ");
	}
	free(prompt);
	return (0);
}

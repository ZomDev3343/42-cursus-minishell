/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/15 14:53:05 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_line(char *line)
{
	t_token	*tlist;

	tlist = tokenize(line);
	print_token_list(tlist);
	free_token(tlist);
}

int	main(void)
{
	char	*line;

	line = readline("minishell > ");
	while (line)
	{
		parse_line(line);
		free(line);
		line = readline("minishell > ");
	}
	return (0);
}

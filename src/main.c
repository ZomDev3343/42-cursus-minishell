/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/18 13:19:43 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_line(char *line)
{
	t_token		*tlist;
	t_command	*cmds;

	cmds = NULL;
	tlist = tokenize(line);
	print_token_list(tlist);
	parse_commands(tlist, &cmds);
	print_commands(cmds);
	free_token(tlist);
}

int	main(void)
{
	char	*line;

	line = readline("minishell > ");
	while (line && line[0] != '\0')
	{
		parse_line(line);
		free(line);
		line = readline("minishell > ");
	}
	return (0);
}

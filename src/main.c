/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/23 13:41:08 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_line(char *line, t_env *env)
{
	t_token		*tlist;
	t_command	*cmds;

	cmds = NULL;
	tlist = tokenize(line, env);
	print_token_list(tlist);
	parse_commands(tlist, &cmds);
	print_commands(cmds);
	free_command(cmds);
	free_token(tlist);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env;

	ac = ac + 1 - 1;
	*av = *av;
	env = make_env(envp);
	line = readline("minishell > ");
	while (line && line[0] != '\0')
	{
		parse_line(line, env);
		free(line);
		line = readline("minishell > ");
	}
	ft_free(line);
	free_env(env);
	return (0);
}

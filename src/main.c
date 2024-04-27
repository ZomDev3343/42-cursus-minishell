/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/04/27 13:31:58 by tohma            ###   ########.fr       */
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
	setup_signal_handler();
	line = readline("minishell > ");
	while (line && line[0] != '\0')
	{
		parse_line(line, env);
		free(line);
		line = readline("minishell > ");
		if (line[0] != '\0')
			add_history(line);
	}
	return (ft_free(line), free_env(env), 0);
}

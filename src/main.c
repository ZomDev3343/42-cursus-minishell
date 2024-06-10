/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/06/10 16:16:37 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_and_execute_line(char *line, t_env *env, t_exec *exec)
{
	t_token		*tlist;
	t_command	*cmds;

	if (line[0] == '\0')
	{
		free(exec);
		return ;
	}
	cmds = NULL;
	tlist = tokenize(line, exec);
	parse_commands(tlist, &cmds);
	free_token(tlist);
	if (!check_commands(cmds))
	{
		free(exec);
		return (free_command(cmds), (void) 0);
	}
	if (is_command_valid(cmds, env) == 1)
		handle_execution(line, cmds, env, exec);
	/*else
		free(exec);*/
	free_command(cmds);
}

static void	manage_exec_error_code(int exit_code_save, t_env *env, t_exec *exec)
{
	exec->env = env;
	exec->exit_code = exit_code_save;
	exec->error_flag = 0;
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	int		exit_code_save;
	t_exec	*exec;
	t_env	*env;

	(void)ac;
	(void)av;
	env = make_env(envp);
	exec = NULL;
	exit_code_save = 0;
	setup_signal_handler();
	line = readline("minishell > ");
	if (line && line[0] != '\0')
		add_history(line);
	while (line)
	{
		if (!exec)
			exec = make_exec_structure();
		manage_exec_error_code(exit_code_save, env, exec);
		parse_and_execute_line(line, env, exec);
		exit_code_save = exec->exit_code;
		free(line);
		line = readline("minishell > ");
		if (line && line[0] != '\0')
			add_history(line);
	}
	rl_clear_history();
	return (ft_free(line), free_env(env), 0);
}

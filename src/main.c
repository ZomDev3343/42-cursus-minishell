/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/06/13 15:31:40 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_signals;

static void	parse_and_execute_line(char *line, t_env *env, t_exec *exec)
{
	t_token		*tlist;
	t_command	*cmds;

	if (line == NULL)
		return (free(exec));
	if (line[0] == '\0')
		return ;
	cmds = NULL;
	tlist = tokenize(line, exec);
	parse_commands(tlist, &cmds);
	free_token(tlist);
	g_signals = 0;
	if (!check_commands(cmds))
	{
		free(exec);
		return (free_command(cmds), (void) 0);
	}
	if (is_command_valid(cmds, env) == 1)
		handle_execution(line, cmds, env, exec);
	else
		exec->exit_code = 1;
	free_command(cmds);
}

static void	manage_exec_error_code(int exit_code_save, t_env *env, t_exec *exec)
{
	exec->env = env;
	exec->exit_code = exit_code_save;
	exec->error_flag = 0;
}

static void	free_in_minishell_loop(t_exec *exec, char *line)
{
	free(exec);
	free(line);
}

void	minishell_loop(t_env *env)
{
	char	*line;
	int		exit_code_save;
	t_exec	*exec;

	setup_signal_handler();
	exit_code_save = 0;
	g_signals = 0;
	line = readline("minishell > ");
	if (line && line[0] != '\0')
		add_history(line);
	while (line)
	{
		exec = make_exec_structure();
		manage_exec_error_code(exit_code_save, env, exec);
		parse_and_execute_line(line, env, exec);
		exit_code_save = exec->exit_code;
		free_in_minishell_loop(exec, line);
		line = readline("minishell > ");
		if (line && line[0] != '\0')
			add_history(line);
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	(void)ac;
	(void)av;
	env = make_env(envp);
	minishell_loop(env);
	return (free_env(env), 0);
}

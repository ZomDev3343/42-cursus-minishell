/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/17 14:48:57 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_process(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	printf("\n---- ENV BEFORE PROCESS ----\n");
	print_env(env);
	//update_env(get_current_working_directory(), "PWD", env);
	if (i > 0)
	{
		dup2(exec->pipes[i - 1][0], STDIN_FILENO);
		close(exec->pipes[i - 1][1]);
	}
	if (i < exec->cmd_nb - 1)
	{
		dup2(exec->pipes[i][1], STDOUT_FILENO);
		close(exec->pipes[i][0]);
	}
	if (handle_redirections(cmd->redirections, exec) == 1)
		return ;
	if (cmd->builtin_flag > NOT_A_BUILTIN)
	{
		choose_builtin_path(cmd, env);
		exit(EXIT_SUCCESS);
	}
	else
		execve(found_path(cmd->parts[0], env), cmd->parts, build_env(env));
}

void	parent_process(int i, t_exec *exec)
{
	if (i > 0)
		close(exec->pipes[i - 1][0]);
	if (i < exec->cmd_nb - 1)
		close(exec->pipes[i][1]);
	wait(NULL);
	dup2(exec->fd_stdout, STDOUT_FILENO);
	dup2(exec->fd_stdin, STDIN_FILENO);
	close(exec->fd_stdout);
}

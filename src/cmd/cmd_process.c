/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/20 16:14:19 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_process(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	handle_redir_entering_exec(i, exec);
	if (handle_redirections(cmd->redirections, exec) == 1)
		return ;
	if (check_builtin_path(cmd) == 0)
	{
		builtin_in_child(cmd, env);
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

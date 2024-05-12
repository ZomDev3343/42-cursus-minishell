/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/12 21:20:51 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	enter_child_process(t_command *cmd, t_env *env)
{
	execve(found_path(cmd->parts[0], env), cmd->parts, NULL);
	perror("ERROR : execve failed.\n");
	exit(EXIT_FAILURE);
}

void	enter_parent_process(t_exec *exec)
{
	wait(NULL);
	dup2(exec->fd_stdout, STDOUT_FILENO);
	dup2(exec->fd_stdin, STDIN_FILENO);
	close(exec->fd_stdout);
}

void	manage_process(int i, int pid, t_exec *exec, t_command *cmd, t_env *env)
{
	if (pid == 0)
	{
		if (i > 0) // Handle input from the previous pipe if it's not the first command.
		{
			dup2(exec->pipes[i - 1][0], STDIN_FILENO);
			close(exec->pipes[i - 1][1]);
		}
		if (i < exec->cmd_nb - 1) // Handle output for the next pipe if it's not the last command.
		{
			dup2(exec->pipes[i][1], STDOUT_FILENO);
			close(exec->pipes[i][0]);
		}
		if (handle_redirections(cmd->redirections, exec) == 1)
			return ;
		enter_child_process(cmd, env);
	}
	else
	{
		if (i > 0) // close pipe end.
			close(exec->pipes[i - 1][0]);
		if (i < exec->cmd_nb - 1) // close read end.
			close(exec->pipes[i][1]);
		enter_parent_process(exec);
	}
}

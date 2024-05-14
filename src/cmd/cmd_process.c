/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/13 17:28:02 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_process(int i, t_exec *exec, t_command *cmd, t_env *env)
{
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
	/*if (cmd->builtin_flag > 0)
		choose_builtin_path();
	else*/
	execve(found_path(cmd->parts[0], env), cmd->parts, NULL);
	perror("ERROR : execve failed.\n");
	exit(EXIT_FAILURE);
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

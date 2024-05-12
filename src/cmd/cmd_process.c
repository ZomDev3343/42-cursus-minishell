/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/11 18:22:44 by fbelotti         ###   ########.fr       */
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

void	enter_child_process_b(int **pipes, int i, int pipe_nb, t_command *cmd)
{
	t_exec	*exec;

	exec = make_exec_structure();
	if (i != 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (cmd->next)
		dup2(pipes[i][1], STDOUT_FILENO);
	cleanup_pipes(pipes, pipe_nb);
	handle_redirections(cmd->redirections, exec);
	execve(cmd->parts[0], cmd->parts, NULL);
}

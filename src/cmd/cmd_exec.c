/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/06 20:38:34 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_pid(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : during fork creation\n");
		return (1);
	}
	if (pid == 0)
	{
		handle_redir_entering_exec(i, exec);
		child_process(exec, cmd, env);
	}
	else
	{
		handle_redir_leaving_exec(i, exec);
		exec->pids[i] = pid;
	}
	return (0);
}

void	exec_command(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	if (!cmd)
		return ;
	if (handle_redirections(cmd->redirections, exec) == 1)
		return ;
	if (exec->pipes == NULL && check_builtin_path(cmd) == 1)
		builtin_out_child(i, exec, cmd, env);
	else
	{
		if (handle_pid(i, exec, cmd, env) == 1)
			return ;
	}
	exec_command(i + 1, exec, cmd->next, env);
}

void	handle_waitpid(t_exec *exec, t_command *cmd)
{
	int	i;
	int	status;

	i = 0;
	status = -1;
	while (i < exec->cmd_nb)
	{
		//printf("process : %d | status : %d\n", exec->pids[i], status);
		waitpid(exec->pids[i], &status, 0);
		if (status == 0)
		{
			if (search_for_exit(cmd) == 0)
				exec->exit_code = status;
		}
		else
		{
			exec->exit_code = status;
			free(exec->pids);
			return ;
		}
		i++;
	}
	free(exec->pids);
}

void	handle_execution(char *line, t_command *cmd, t_env *env, t_exec *exec)
{
	manage_exec_structure(line, exec, cmd);
	exec_command(0, exec, cmd, env);
	if (exec->cmd_nb >= 1)
		handle_waitpid(exec, cmd);
	if (exec->pipes)
		free_pipes(exec->pipes, (exec->cmd_nb - 1));
	dup2(exec->fd_stdin, STDIN_FILENO);
	dup2(exec->fd_stdout, STDOUT_FILENO);
	close(exec->fd_stdin);
	close(exec->fd_stdout);
	free(exec);
}

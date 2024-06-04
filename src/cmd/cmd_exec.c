/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/04 15:33:59 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_pid(int i, int pid, t_exec *exec, t_command *cmd, t_env *env)
{
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
}

void	exec_command(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	int	pid;

	if (!cmd)
		return ;
	if (exec->pipes == NULL && check_builtin_path(cmd) == 1)
		builtin_out_child(i, exec, cmd, env);
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("ERROR : during fork creation\n");
			return ;
		}
		else
			handle_pid(i, pid, exec, cmd, env);
	}
	exec_command(i + 1, exec, cmd->next, env);
}

void	manage_exec_structure(char *line, t_exec *exec, t_command *cmd)
{
	exec->cmd_nb = get_nb_of_commands(cmd);
	exec->pipes = create_pipes(exec->cmd_nb - 1);
	exec->line = line;
	exec->fd_stdin = dup(STDIN_FILENO);
	exec->fd_stdout = dup(STDOUT_FILENO);
	exec->pids = malloc(sizeof(int) * exec->cmd_nb);
	exec->exit_status = 0;
}

void	handle_waitpid(t_exec *exec)
{
	int	i;

	i = 0;
	while (i < exec->cmd_nb)
	{
		waitpid(exec->pids[i], &basic_status, 0);
		if (basic_status != 0)
			return ;
		i++;
	}
	free(exec->pids);
}

void	handle_execution(char *line, t_command *cmd, t_env *env, t_exec *exec)
{
	manage_exec_structure(line, exec, cmd);
	exec_command(0, exec, cmd, env);
	handle_waitpid(exec);
	if (exec->pipes)
		free_pipes(exec->pipes, (exec->cmd_nb - 1));
	dup2(exec->fd_stdin, STDIN_FILENO);
	dup2(exec->fd_stdout, STDOUT_FILENO);
	close(exec->fd_stdin);
	close(exec->fd_stdout);
}

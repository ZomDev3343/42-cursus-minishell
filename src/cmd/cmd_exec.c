/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/01 21:06:20 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
}

void	handle_waitpid(t_exec *exec)
{
	int	i;
	int	status;

	i = 0;
	while (i < exec->cmd_nb)
	{
		waitpid(exec->pids[i], &status, 0);
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

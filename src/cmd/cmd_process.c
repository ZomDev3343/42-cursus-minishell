/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:26:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/12 14:30:01 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_all_in_child(t_exec *exec, t_command *cmd, t_env *env)
{
	if (env)
		free_env(env);
	if (exec->pids)
		free(exec->pids);
	if (exec->pipes)
		free_pipes(exec->pipes, (exec->cmd_nb - 1));
	if (exec)
		free(exec);
	if (cmd)
		free_command(cmd);
}

void	child_process(t_exec *exec, t_command *cmd, t_env *env)
{
	if (cmd->builtin_flag)
	{
		builtin_in_child(cmd, env, exec);
		free_all_in_child(exec, cmd, env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (cmd->parts[0] != NULL)
		{
			if (execve(found_path(cmd->parts[0], env), cmd->parts,
					build_env(env)) == -1)
			{
				free_all_in_child(exec, cmd, env);
				printf("-minishell: %s: No such file or directory\n",
					cmd->parts[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			exit(EXIT_SUCCESS);
	}
}

void	close_unused_pipes(t_exec *exec, int i)
{
	int	j;

	j = 0;
	while (j < exec->cmd_nb - 1)
	{
		if (j != i - 1)
			close(exec->pipes[j][0]);
		if (j != i)
			close(exec->pipes[j][1]);
		j++;
	}
}

void	handle_redir_leaving_exec(int i, t_exec *exec)
{
	if (i > 0)
		close(exec->pipes[i - 1][0]);
	if (i < exec->cmd_nb - 1)
		close(exec->pipes[i][1]);
}

void	handle_redir_entering_exec(int i, t_exec *exec)
{
	if (i > 0)
		dup2(exec->pipes[i - 1][0], STDIN_FILENO);
	if (i < exec->cmd_nb - 1)
		dup2(exec->pipes[i][1], STDOUT_FILENO);
	close_unused_pipes(exec, i);
}

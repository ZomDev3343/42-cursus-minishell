/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/13 10:35:12 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_command(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	int		pid;

	if (!cmd)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : during fork creation\n");
		return ;
	}
	if (pid == 0)
		child_process(i, exec, cmd, env);
	else
		parent_process(i, exec);
	exec_command(i + 1, exec, cmd->next, env);
}

void	handle_execution(t_command *cmd, t_env *env)
{
	t_exec	*exec;

	exec = make_exec_structure();
	exec->cmd_nb = get_nb_of_commands(cmd);
	exec->pipes = create_pipes(exec->cmd_nb - 1);
	exec_command(0, exec, cmd, env);
	if (exec->pipes)
		free_pipes(exec->pipes, exec->cmd_nb - 1);
	free(exec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/12 21:20:37 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_single_cmd(t_command *cmd, t_env *env)
{
	t_exec	*exec;
	int		pid;

	exec = make_exec_structure();
	if (handle_redirections(cmd->redirections, exec) == 1)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : during fork creation\n");
		return ;
	}
	if (pid == 0)
		enter_child_process(cmd, env);
	else
		enter_parent_process(exec);
}

void	exec_multiple_cmd(int i, t_exec *exec, t_command *cmd, t_env *env)
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
	manage_process(i, pid, exec, cmd, env);
	exec_multiple_cmd(i + 1, exec, cmd->next, env);
}

void	choose_exec_path(t_command *cmd, t_env *env)
{
	t_exec	*exec;

	exec = make_exec_structure();
	exec->cmd_nb = get_nb_of_commands(cmd);
	if (exec->cmd_nb == 1)
		exec_single_cmd(cmd, env);
	else if (exec->cmd_nb > 1)
	{
		exec->pipes = create_pipes(exec->cmd_nb - 1);
		exec_multiple_cmd(0, exec, cmd, env);
		//free_pipes;
	}
}

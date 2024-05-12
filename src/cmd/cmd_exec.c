/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/11 18:23:01 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	single_execution(t_command *cmd, t_env *env)
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

void	multiple_execution(int pipe_nb, t_command *cmd, t_env *env)
{
	t_command	*current_cmd;
	int			**pipes;
	int			pid;
	int			i;

	i = 0;
	pipes = creates_pipes(pipe_nb, pipes);
	while (current_cmd)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("ERROR : while forking process.\n");
			cleanup_pipes(pipes, pipe_nb);
			return ;
		}
		else if (pid == 0)
			enter_child_process_b(pipes, i, pipe_nb, current_cmd);
		current_cmd = current_cmd->next;
		i++;
	}
	close_pipes(pipes, pipe_nb);
}

void	choose_exec_path(t_command *cmd, t_env *env)
{
	int	cmd_nb;

	cmd_nb = get_nb_of_commands(cmd);
	if (cmd_nb == 1)
		single_execution(cmd, env);
	else if (cmd_nb > 1)
		multiple_execution(cmd_nb - 1, cmd, env);
}

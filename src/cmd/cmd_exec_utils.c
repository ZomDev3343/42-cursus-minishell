/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:10:04 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/07 12:07:19 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	manage_exec_structure(char *line, t_exec *exec, t_command *cmd)
{
	exec->cmd_nb = get_nb_of_commands(cmd);
	exec->pipes = create_pipes(exec->cmd_nb - 1);
	exec->line = line;
	exec->fd_stdin = dup(STDIN_FILENO);
	exec->fd_stdout = dup(STDOUT_FILENO);
	exec->pids = ft_calloc(exec->cmd_nb, sizeof(int));
}

int	search_for_exit(t_command *cmd)
{
	t_command	*current;

	current = cmd;
	while (current)
	{
		if (cmd->builtin_flag == BUILTIN_EXIT || cmd->builtin_flag == BUILTIN_ECHO)
			return (1);
		current = current->next;
	}
	return (0);
}

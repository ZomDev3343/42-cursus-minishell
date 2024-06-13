/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:10:04 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/13 11:34:16 by fbelotti         ###   ########.fr       */
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
		if (cmd->builtin_flag == BUILTIN_EXIT
			|| cmd->builtin_flag == BUILTIN_ECHO)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	check_command_path_flag(t_command *cmd, t_env *env)
{
	int	path_flag;

	if (cmd->builtin_flag == 0 && cmd->parts[0] != NULL)
	{
		path_flag = check_cmd_path(cmd->parts[0], env);
		if (path_flag == 0)
		{
			printf("minishell: %s: command not found\n", cmd->parts[0]);
			return (0);
		}
		else if (path_flag == 2)
			return (2);
	}
	return (1);
}

int	is_command_valid(t_command *cmds, t_env *env)
{
	t_command	*cur;
	int			status;

	cur = cmds;
	while (cur)
	{
		status = check_command_path_flag(cur, env);
		if (status == 0)
			return (0);
		else if (status == 2)
			return (0);
		cur = cur->next;
	}
	return (1);
}

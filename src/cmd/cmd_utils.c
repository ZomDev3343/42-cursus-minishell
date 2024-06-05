/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:41:11 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/05 14:24:12 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exec	*make_exec_structure(void)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	if (!exec)
	{
		perror("ERROR : allocating exec structure\n");
		exit(EXIT_FAILURE);
	}
	return (exec);
}

int	get_nb_of_commands(t_command *cmd)
{
	int	cmd_nb;

	cmd_nb = 0;
	while (cmd)
	{
		cmd_nb++;
		cmd = cmd->next;
	}
	return (cmd_nb);
}

void	ft_free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_pipes(int **pipes, int pipe_nb)
{
	int	i;

	i = 0;
	while (i < pipe_nb)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

int	is_command_valid(t_command *cmds, t_env *env)
{
	t_command	*curr;
	int			error_flag;

	curr = cmds;
	error_flag = 0;
	while (curr)
	{
		if (curr->builtin_flag == 0)
		{
			if (check_cmd_path(curr->parts[0], env) == 0)
			{
				error_flag = 1;
				printf("-minishell: %s: command not found\n", curr->parts[0]);
			}
		}
		curr = curr->next;
	}
	if (error_flag == 1)
		return (0);
	else
		return (1);
}

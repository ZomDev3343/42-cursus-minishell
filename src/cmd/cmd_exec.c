/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/03 18:32:43 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	single_execution(t_command *cmd, t_env *env)
{
	t_exec	*exec;
	int		pid;

	exec = make_exec_structure();
	if (handle_redirections(cmd->redirections) == 1)
	{
		perror("ERROR : during redirection process\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : during fork creation\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		enter_child_process(cmd, env);
	else
		enter_parent_process(exec);
}

void	choose_exec_path(t_command *cmd, t_env *env)
{
	int	cmd_nb;

	cmd_nb = get_nb_of_commands(cmd);
	if (cmd_nb == 1)
		single_execution(cmd, env);
	/*else
		create_pipe();*/
}

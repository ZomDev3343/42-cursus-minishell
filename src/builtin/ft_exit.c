/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/21 23:11:52 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_exec *exec, t_command *cmd, t_env *env)
{
	int	status;

	status = 0;
	if (cmd->parts[1])
		status = ft_atoi(cmd->parts[1]);
	free_command(cmd);
	free_env(env);
	free_pipes(exec->pipes, exec->cmd_nb - 1);
	free(exec->line);
	free(exec);
	exit(status);
}

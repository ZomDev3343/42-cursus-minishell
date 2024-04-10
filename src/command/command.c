/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:30:22 by tohma             #+#    #+#             */
/*   Updated: 2024/04/09 16:08:20 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	free_command(t_command *cmd)
{
	if (!cmd)
		return (FALSE);
	free_parts(cmd->cmd_args);
	ft_free(cmd);
	return (TRUE);
}

t_command	*newcmd(char **cmd_parts)
{
	t_command	*cmd;

	cmd = (t_command *) ft_calloc(1, sizeof(t_command));
	if (!cmd || !cmd_parts)
		return (NULL);
	cmd->cmd_name = cmd_parts[0];
	cmd->cmd_args = cmd_parts;
	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:16:31 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 17:11:06 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*newcmd(char **cmd_parts, t_redirections *redirections)
{
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->parts = cmd_parts;
	cmd->redirections = redirections;
	cmd->next = NULL;
	return (cmd);
}

t_command	*parse_commands(t_token *tlist)
{
	t_command		*cmd;
	t_redirections	*redirections;
	int				cur_id;

	cur_id = 0;
	cmd = NULL;
	redirections = NULL;
	while (tlist)
	{
		if (tlist->cmd_id == cur_id)
		{

		}
		else
			cur_id++;
		tlist = tlist->next;
	}

}

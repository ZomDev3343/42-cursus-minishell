/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:16:31 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 19:58:59 by tohma            ###   ########.fr       */
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
	t_redirections	*redirections;
	int				cur_id;

	cur_id = 0;
	redirections = NULL;
	while (tlist)
	{
		if (tlist->used)
			continue ;
		if (tlist->cmd_id == cur_id)
		{
			parse_redirection(&redirections, tlist);
		}
		else
			break ;
		tlist = tlist->next;
	}
	print_redirections(redirections);
	return (NULL);
}

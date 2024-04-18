/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:16:31 by truello           #+#    #+#             */
/*   Updated: 2024/04/18 14:07:53 by tohma            ###   ########.fr       */
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

static void	push_command(t_command **cmds, t_command *cmd)
{
	t_command	*tmp;

	if (!cmds)
		return ;
	if (!*cmds)
		*cmds = cmd;
	else
	{
		tmp = *cmds;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd;
	}
}

void	parse_commands(t_token *tlist, t_command **cmds)
{
	t_command_part	*cmd_parts;
	t_redirections	*redirections;
	int				cur_id;

	cur_id = 0;
	cmd_parts = NULL;
	redirections = NULL;
	while (tlist)
	{
		if (!tlist->used && tlist->cmd_id == cur_id)
			if (!parse_redirection(&redirections, tlist))
				push_command_part(&cmd_parts, ft_strcpy(tlist->data));
		if ((!tlist->used && tlist->cmd_id != cur_id) || !tlist->next)
		{
			push_command(cmds, newcmd(build_parts(cmd_parts), redirections));
			redirections = NULL;
			cmd_parts = NULL;
			cur_id++;
			if (!tlist->next)
				tlist = tlist->next;
			continue ;
		}
		tlist = tlist->next;
	}
}

void	print_commands(t_command *cmds)
{
	while (cmds)
	{
		printf("--- Command ---\n");
		print_parts(cmds->parts);
		print_redirections(cmds->redirections);
		printf("--- Command ---\n");
		cmds = cmds->next;
	}
}

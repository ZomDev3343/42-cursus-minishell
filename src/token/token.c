/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:28 by truello           #+#    #+#             */
/*   Updated: 2024/03/29 16:27:47 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*tkn_to_cmd(t_token *token)
{
	t_command	*cmd;
	char		**cmd_parts;

	cmd = (t_command *) ft_calloc(1, sizeof(t_command));
	if (!cmd || !token || !token->data)
		return (NULL);
	cmd_parts = ft_split(token->data, ' ');
	if (!cmd_parts)
		return (free(cmd), NULL);
	cmd->cmd_name = cmd_parts[0];
	cmd->cmd_args = cmd_parts;
	return (cmd);
}

t_token	*newtoken(char *data, int flag)
{
	t_token	*res;

	res = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!res)
		return (NULL);
	res->data = data;
	res->flag = flag;
	return (res);
}

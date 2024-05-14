/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:40 by tohma             #+#    #+#             */
/*   Updated: 2024/05/14 15:45:03 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Takes string parts and builds an array containing every part
 * (frees the original linked list)
*/
char	**build_parts(t_string_part *cmd_parts)
{
	char			**res;
	t_string_part	*tmp;
	int				len;
	int				i;

	len = 0;
	i = -1;
	tmp = cmd_parts;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	res = ft_calloc(len + 1, sizeof(char *));
	if (!res)
		return (NULL);
	tmp = cmd_parts;
	while (++i < len)
	{
		res[i] = ft_strcpy(tmp->part);
		tmp = tmp->next;
	}
	return (free_str_parts(cmd_parts), res);
}

void	set_builtin_flag(t_command *cmd)
{
	if (ft_strcmp(cmd->parts[0], "echo"))
		cmd->builtin_flag = BUILTIN_ECHO;
	else if (ft_strcmp(cmd->parts[0], "cd"))
		cmd->builtin_flag = BUILTIN_CD;
	else if (ft_strcmp(cmd->parts[0], "pwd"))
		cmd->builtin_flag = BUILTIN_PWD;
	else if (ft_strcmp(cmd->parts[0], "export"))
		cmd->builtin_flag = BUILTIN_EXPORT;
	else if (ft_strcmp(cmd->parts[0], "unset"))
		cmd->builtin_flag = BUILTIN_UNSET;
	else if (ft_strcmp(cmd->parts[0], "env"))
		cmd->builtin_flag = BUILTIN_ENV;
	else if (ft_strcmp(cmd->parts[0], "exit"))
		cmd->builtin_flag = BUILTIN_EXIT;
}

void	free_command(t_command *cmd)
{
	if (!cmd)
		return ;
	if (cmd->next)
		free_command(cmd->next);
	free_parts(cmd->parts);
	free_redirections(cmd->redirections);
	free(cmd);
}

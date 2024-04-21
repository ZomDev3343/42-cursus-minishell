/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:40 by tohma             #+#    #+#             */
/*   Updated: 2024/04/21 15:18:32 by tohma            ###   ########.fr       */
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

void	free_command(t_command *cmd)
{
	if (cmd->next)
		free_command(cmd->next);
	free_parts(cmd->parts);
	free_redirections(cmd->redirections);
	free(cmd);
}

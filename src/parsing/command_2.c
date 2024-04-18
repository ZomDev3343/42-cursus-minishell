/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:40 by tohma             #+#    #+#             */
/*   Updated: 2024/04/18 12:33:09 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_cmd_parts(t_command_part *parts)
{
	if (!parts)
		return ;
	if (parts->next)
		free_cmd_parts(parts->next);
	free(parts->part);
	free(parts);
}

void	push_command_part(t_command_part **cmd_parts, char *part)
{
	t_command_part	*cmd_part;
	t_command_part	*tmp;

	if (!cmd_parts)
		return ;
	cmd_part = ft_calloc(1, sizeof(t_command_part));
	if (!cmd_part)
		return ;
	cmd_part->part = part;
	if (!*cmd_parts)
		*cmd_parts = cmd_part;
	else
	{
		tmp = *cmd_parts;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd_part;
	}
}

char	**build_parts(t_command_part *cmd_parts)
{
	char			**res;
	t_command_part	*tmp;
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
	return (free_cmd_parts(cmd_parts), res);
}

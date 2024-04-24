/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:59:48 by truello           #+#    #+#             */
/*   Updated: 2024/04/23 20:40:50 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*newtoken(char *data, int cmd_id)
{
	t_token	*token;

	if (!data)
		return (NULL);
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->data = data;
	token->cmd_id = cmd_id;
	return (token);
}

static void	push_token(t_token **toklist, t_token *token)
{
	t_token	*tmp;

	if (!toklist)
		return ;
	if (!*toklist)
		*toklist = token;
	else
	{
		tmp = *toklist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}

void	print_token_list(t_token *toklist)
{
	while (toklist)
	{
		printf("%s CMD:%d\n", toklist->data, toklist->cmd_id);
		toklist = toklist->next;
	}
}

void	free_token(t_token *token)
{
	if (!token)
		return ;
	if (token->next)
		free_token(token->next);
	free(token->data);
	free(token);
}

t_token	*tokenize(char *line, t_env *env)
{
	t_token	*token;
	char	*token_part;
	char	**cmds_part;
	int		i;
	int		parts_index;

	token = NULL;
	cmds_part = ft_split(line, '|');
	parts_index = -1;
	while (++parts_index < get_parts_size(cmds_part))
	{
		i = ft_nstrchr_i(cmds_part[parts_index], ' ');
		while (i < ft_strlen(cmds_part[parts_index]))
		{
			token_part = ft_strcpy_wsp(cmds_part[parts_index] + i, &i);
			push_token(&token, newtoken(rem_quotes(token_part, env),
					parts_index));
			free(token_part);
		}
	}
	return (free_parts(cmds_part), token);
}

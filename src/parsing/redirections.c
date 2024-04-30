/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:43:06 by truello           #+#    #+#             */
/*   Updated: 2024/04/30 19:12:35 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redirections	*newredirection(char *path, int mode)
{
	t_redirections	*res;

	res = ft_calloc(1, sizeof(t_redirections));
	if (!res)
		return (NULL);
	res->path = path;
	res->mode = mode;
	res->next = NULL;
	return (res);
}

static int	get_redirection_mode(char *s)
{
	if (*s == '<')
	{
		if (ft_strncmp(s, "<<", 2))
			return (REDIR_HD);
		return (REDIR_IN);
	}
	else if (*s == '>')
	{
		if (ft_strncmp(s, ">>", 2))
			return (REDIR_APP);
		return (REDIR_OUT);
	}
	return (NO_REDIR);
}

t_redirections	*get_redirection(t_token *token, int mode)
{
	t_redirections	*res;
	int				path_index;

	res = ft_calloc(1, sizeof(t_redirections));
	if (!res)
		return (NULL);
	path_index = ft_strchr_i(token->data, get_redirection_char(mode)) + 1
		+ (mode == REDIR_APP || mode == REDIR_HD);
	if (token->data[path_index] != '\0')
	{
		token->used = 1;
		res->path = ft_strcpy(token->data + path_index);
	}
	else
	{
		if (!token->next)
			return (free(res), NULL);
		token->used = 1;
		token->next->used = 1;
		res->path = ft_strcpy(token->next->data);
	}
	res->mode = mode;
	return (res);
}

int	parse_redirection(t_redirections **redirections, t_token *token)
{
	int				redir_mode;
	t_redirections	*newredir;

	if (!redirections)
		return (FALSE);
	redir_mode = get_redirection_mode(token->data);
	if (redir_mode == NO_REDIR || token->used)
		return (FALSE);
	newredir = get_redirection(token, redir_mode);
	if (!newredir)
		return (FALSE);
	push_redirections(redirections, newredir);
	return (TRUE);
}

void	push_redirections(t_redirections **redirections,
		t_redirections *newredir)
{
	t_redirections	*tmp;

	if (!redirections)
		return ;
	if (!*redirections)
		*redirections = newredir;
	else
	{
		tmp = *redirections;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newredir;
	}
}

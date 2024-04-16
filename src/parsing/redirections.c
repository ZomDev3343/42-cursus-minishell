/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:43:06 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 20:27:24 by tohma            ###   ########.fr       */
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
		if (ft_strncmp(s, "<<", 2) == 0)
			return (REDIR_HD);
		return (REDIR_IN);
	}
	else if (*s == '>')
	{
		if (ft_strncmp(s, ">>", 2) == 0)
			return (REDIR_APP);
		return (REDIR_OUT);
	}
	return (NO_REDIR);
}

// A tester imperativement
t_redirections	*get_redirection(t_token *token, int mode)
{
	t_redirections	*res;
	int				path_index;

	res = ft_calloc(1, sizeof(t_redirections));
	if (!res)
		return (NULL);
	path_index = ft_nstrchr_i(token->data, get_redirection_char(mode));
	if (path_index < ft_strlen(token->data))
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

void	parse_redirection(t_redirections **redirections, t_token *token)
{
	int				redir_mode;

	if (!redirections)
		return ;
	redir_mode = get_redirection_mode(token->data);
	if (redir_mode == NO_REDIR || token->used)
		return ;
	push_redirections(redirections, get_redirection(token, redir_mode));
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

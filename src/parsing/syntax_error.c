/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:47:53 by tohma             #+#    #+#             */
/*   Updated: 2024/06/05 17:56:01 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_redirections(t_redirections *redirections)
{
	int	path_len;

	while (redirections)
	{
		path_len = ft_strlen(redirections->path);
		if (ft_strchr_i(redirections->path, '>') < path_len
			|| ft_strchr_i(redirections->path, '<') < path_len)
			return (FALSE);
		redirections = redirections->next;
	}
	return (TRUE);
}

int	check_commands(t_command *cmds)
{
	while (cmds)
	{
		if (!check_redirections(cmds->redirections))
			return (printf("syntax error\n"), FALSE);
		cmds = cmds->next;
	}
	return (TRUE);
}

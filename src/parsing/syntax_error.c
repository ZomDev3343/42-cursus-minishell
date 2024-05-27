/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:47:53 by tohma             #+#    #+#             */
/*   Updated: 2024/05/27 15:21:44 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	are_command_args_valid(char **args)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (args[++i])
// 	{
// 		j = -1;
// 		while (args[i][++j])
// 			if (args[i][j] == '<' || args[i][j] == '>')
// 				return (FALSE);
// 	}
// 	return (TRUE);
// }

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

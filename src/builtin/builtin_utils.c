/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/15 14:47:56 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	choose_builtin_path(t_command *cmd, t_env *env)
{
	if (cmd->builtin_flag == BUILTIN_ECHO)
		ft_echo(cmd);
	else if (cmd->builtin_flag == BUILTIN_CD)
		ft_cd(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_PWD)
		ft_pwd(env);
/*	else if (cmd->builtin_flag == BUILTIN_EXPORT)
		ft_export();
	else if (cmd->builtin_flag == BUILTIN_UNSET)
		ft_unset();
	else if (cmd->builtin_flag == BUILTIN_ENV)
		ft_env();
	else if (cmd->builtin_flag == BUILTIN_EXIT)
		ft_exit(); */
}

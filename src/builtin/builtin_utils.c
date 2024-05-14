/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/14 17:43:05 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	choose_builtin_path(t_command *cmd)
{
	if (cmd->builtin_flag == BUILTIN_ECHO)
		ft_echo(cmd);
/*	else if (cmd->builtin_flag == BUILTIN_CD)
		ft_cd();
	else if (cmd->builtin_flag == BUILTIN_PWD)
		ft_pwd();
	else if (cmd->builtin_flag == BUILTIN_EXPORT)
		ft_export();
	else if (cmd->builtin_flag == BUILTIN_UNSET)
		ft_unset();
	else if (cmd->builtin_flag == BUILTIN_ENV)
		ft_env();
	else if (cmd->builtin_flag == BUILTIN_EXIT)
		ft_exit(); */
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/04 11:55:54 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_cd_arg(t_command *cmd)
{
	if (cmd->parts[2])
	{
		perror("-minishell: cd: too many arguments\n");
		return (1);
	}
	return (0);
}

int	ft_cd(t_command *cmd, t_env *env)
{
	char	*old_pwd;

	if (check_cd_arg(cmd) == 1)
		return (1);
	old_pwd = get_current_working_directory();
	if (cmd->parts[1])
	{
		if (chdir(cmd->parts[1]) == 0)
		{
			update_env(ft_strdup(old_pwd), ft_strdup("OLDPWD"), env);
			update_env(get_current_working_directory(), ft_strdup("PWD"), env);
		}
		else
			return (1);
	}
	else
	{
		chdir(getenv("HOME"));
		update_env(get_current_working_directory(), ft_strdup("PWD"), env);
		update_env(ft_strdup(old_pwd), ft_strdup("OLDPWD"), env);
	}
	free(old_pwd);
	return (0);
}

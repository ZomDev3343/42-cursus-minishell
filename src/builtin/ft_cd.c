/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/30 01:28:38 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_cd_arg(t_command *cmd)
{
	if (cmd->parts[2])
	{
		perror(" too many arguments\n");
		exit(1);
	}
}

void	ft_cd(t_command *cmd, t_env *env)
{
	char	*old_pwd;

	check_cd_arg(cmd);
	old_pwd = get_current_working_directory();
	if (cmd->parts[1])
	{
		if (chdir(cmd->parts[1]) == 0)
		{
			update_env(ft_strcpy(old_pwd), ft_strcpy("OLDPWD"), env);
			update_env(get_current_working_directory(), ft_strcpy("PWD"), env);
		}
		else
		{
			perror("");
			exit (1);
		}
	}
	else
	{
		chdir(getenv("HOME"));
		update_env(get_current_working_directory(), ft_strcpy("PWD"), env);
		update_env(ft_strcpy(old_pwd), ft_strcpy("OLDPWD"), env);
	}
	free(old_pwd);
}

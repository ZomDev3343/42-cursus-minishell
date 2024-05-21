/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/21 13:46:47 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd(t_command *cmd, t_env *env)
{
	char	*old_pwd;

	old_pwd = get_current_working_directory();
	if (cmd->parts[1])
	{
		if (chdir(cmd->parts[1]) == 0)
		{
			update_env(old_pwd, "OLDPWD", env);
			update_env(get_current_working_directory(), "PWD", env);
		}
		else
			printf("cd: %s: No such file or directory\n", cmd->parts[1]);
	}
	else
	{
		chdir(getenv("HOME"));
		update_env(get_current_working_directory(), "PWD", env);
		update_env(old_pwd, "OLDPWD", env);
	}
	free(old_pwd);
}

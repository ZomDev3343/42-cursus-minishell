/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/06 10:37:57 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_cd_arg(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->parts[i])
		i++;
	if (i <= 2)
		return (0);
	else
	{
		perror("-minishell: cd: too many arguments\n");
		return (1);
	}
}

void	update_env_for_valid_path(char *old_pwd, char *curr_dir, t_env *env)
{
	update_env(ft_strcpy(old_pwd), ft_strcpy("OLDPWD"), env);
	curr_dir = get_current_working_directory();
	update_env(ft_strcpy(curr_dir), ft_strcpy("PWD"), env);
	free(curr_dir);
}

void	update_env_for_home_path(char *old_pwd, char *curr_dir, t_env *env)
{
	chdir(getenv("HOME"));
	curr_dir = get_current_working_directory();
	update_env(ft_strcpy(curr_dir), ft_strcpy("PWD"), env);
	update_env(ft_strcpy(old_pwd), ft_strcpy("OLDPWD"), env);
	free(curr_dir);
}

int	ft_cd(t_command *cmd, t_env *env)
{
	char	*old_pwd;
	char	*curr_dir;

	if (check_cd_arg(cmd) == 1)
		return (1);
	old_pwd = get_current_working_directory();
	curr_dir = NULL;
	if (cmd->parts[1])
	{
		if (chdir(cmd->parts[1]) == 0)
			update_env_for_valid_path(old_pwd, curr_dir, env);
		else
		{
			printf("cd: The directory \"%s\" does not exist\n", cmd->parts[1]);
			free(old_pwd);
			return (1);
		}
	}
	else
		update_env_for_home_path(old_pwd, curr_dir, env);
	free(old_pwd);
	return (0);
}

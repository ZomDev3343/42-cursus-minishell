/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/15 21:42:39 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_current_pwd(t_env *env)
{
	t_env	*current_env;

	current_env = env;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, "PWD", 3))
			return (current_env->content);
		current_env = current_env->next;
	}
	return (NULL);
}

void	ft_cd(t_command *cmd, t_env *env)
{
	/*remove_env_var(&env, "OLDPWD");
	push_env(&env, newenv("OLDPWD", get_current_pwd(env)));
	print_env(env);*/
	if (cmd->parts[1] == NULL)
		chdir(getenv("HOME"));
	else if (ft_strncmp(cmd->parts[1], "..", 2))
		chdir(getenv("OLDPWD"));
	else
	{
		if (!chdir(cmd->parts[1]))
		{
			printf("cd : %s: No such file or directory\n", cmd->parts[1]);
			return ;
		}
	}
}

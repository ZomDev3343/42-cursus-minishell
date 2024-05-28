/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:58 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/29 00:02:19 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	search_for_equal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i - 1] == '-')
			{
				errno = 1;
				perror("");
				exit(1);
			}
			else
				return ;
		}
		i++;
	}
	errno = 0;
	perror("");
	exit(0);
}

void	ft_export(t_command *cmd, t_env *env)
{
	t_env	*current_env;
	char	**new_var;

	search_for_equal(cmd->parts[1], '=');
	new_var = ft_split(cmd->parts[1], '=');
	current_env = env;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, new_var[0], ft_strlen(new_var[0])))
			remove_env_var(env, current_env->name);
		current_env = current_env->next;
	}
	add_env_variable(env, newenv(ft_strcpy(new_var[0]), ft_strcpy(new_var[1])));
	free_parts(new_var);
}

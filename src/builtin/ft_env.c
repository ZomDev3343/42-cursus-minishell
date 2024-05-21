/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/21 10:18:10 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(int flag, t_command *cmd, t_env *env)
{
	t_env	*current_env;
	char	**new_var;

	current_env = env;
	if (flag == 0)
		print_env(env);
	else
	{
		new_var = ft_split(cmd->parts[1], '=');
		while (current_env)
		{
			if (ft_strncmp(current_env->name, new_var[0],
					ft_strlen(new_var[0])))
				remove_env_var(env, current_env->name);
			current_env = current_env->next;
		}
		add_env_variable(env, newenv(new_var[0], new_var[1]));
		print_env(env);
	}
}

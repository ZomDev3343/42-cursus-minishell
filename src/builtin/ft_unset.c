/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:55 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/29 17:23:37 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_command *cmd, t_env *env)
{
	t_env	*current_env;

	if (!cmd->parts[1])
		exit (0);
	current_env = env;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, cmd->parts[1],
				ft_strlen(cmd->parts[1])))
			remove_env_var(env, cmd->parts[1]);
		current_env = current_env->next;
	}
}

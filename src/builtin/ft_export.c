/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:58 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/28 16:48:30 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_export_arg(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && i >= 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_export(t_command *cmd, t_env *env)
{
	t_env	*current_env;
	char	**new_var;

	if (check_export_arg(cmd->parts[1], '=') == 1)
		return ;
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

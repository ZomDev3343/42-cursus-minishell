/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:58 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/29 17:12:21 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0] || ft_isdigit(str[0]) || str[0] == '=')
		return (0);
	while (str[i])
	{
		if (!ft_isalphanum_c(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	check_identifier(char *identifier)
{
	if (!is_valid_identifier(identifier))
	{
		errno = EINVAL;
		perror("export: not a valid identifier");
		free(identifier);
		exit(1);
	}
}

void	check_args(t_command *cmd)
{
	if (!cmd->parts[1])
	{
		errno = EINVAL;
		perror(" not a valid identifier");
		exit(1);
	}
}

void	ft_export(t_command *cmd, t_env *env)
{
	t_env	*current_env;
	char	**new_var;

	check_args(cmd);
	if (ft_strchr(cmd->parts[1], '=') == 0)
	{
		new_var = ft_split(cmd->parts[1], '=');
		check_identifier(new_var[0]);
		current_env = env;
		while (current_env)
		{
			if (ft_strcmp(current_env->name, new_var[0]) == 0)
				remove_env_var(env, current_env->name);
			current_env = current_env->next;
		}
		add_env_variable(env, newenv(ft_strdup(new_var[0]),
				ft_strdup(new_var[1])));
		free_parts(new_var);
	}
	else
	{
		check_identifier(cmd->parts[1]);
		add_env_variable(env, newenv(ft_strdup(cmd->parts[1]), NULL));
	}
}

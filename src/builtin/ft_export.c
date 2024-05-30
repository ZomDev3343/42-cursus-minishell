/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:58 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/30 22:49:43 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_export_operator(char *str, t_exec *exec)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i - 1] == '-' || i < 1)
	{
		perror("not a valid identifier\n");
		exec->exit_status = 1;
		return (1);
	}
	return (0);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (TRUE);
	return (FALSE);
}

int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_export_arg(t_command *cmd, t_exec *exec)
{
	if (!cmd->parts[1])
	{
		perror("not enough arguments\n");
		exec->exit_status = 0;
		return (1);
	}
	if (ft_strchr(cmd->parts[1], '=') == FALSE)
	{
		perror("not a valid identifier\n");
		if (ft_strchr(cmd->parts[1], '-') || is_only_digit(cmd->parts[1]))
			exec->exit_status = 1;
		else
			exec->exit_status = 0;
		return (1);
	}
	else if (check_export_operator(cmd->parts[1], exec) == 1)
		return (1);
	return (0);
}

int	ft_export(t_command *cmd, t_env *env, t_exec *exec)
{
	t_env	*current_env;
	char	**new_var;

	if (check_export_arg(cmd, exec) == 1)
		return (1);
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
	return (0);
}




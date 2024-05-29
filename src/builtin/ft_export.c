/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:58 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/30 01:09:05 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_export_operator(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i - 1] == '-' || i < 1)
	{
		perror("not a valid identifier\n");
		exit(1);
	}
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

void	check_export_arg(t_command *cmd)
{
	if (!cmd->parts[1])
	{
		perror("not enough arguments\n");
		exit(0);
	}
	if (ft_strchr(cmd->parts[1], '=') == FALSE)
	{
		perror("not a valid identifier\n");
		if (ft_strchr(cmd->parts[1], '-') == TRUE)
			exit(1);
		if (is_only_digit(cmd->parts[1]) == TRUE)
			exit(1);
		exit(0);
	}
	else
		check_export_operator(cmd->parts[1]);
}

void	ft_export(t_command *cmd, t_env *env)
{
	t_env	*current_env;
	char	**new_var;

	check_export_arg(cmd);
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




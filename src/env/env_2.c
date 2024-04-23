/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:28:44 by tohma             #+#    #+#             */
/*   Updated: 2024/04/23 13:07:26 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Expects a string starting with '$' and gives the name after it
 *
 * @param var_name String containing the variable name
 * @return (char*) Ex: $PATH -> PATH
 */
static char	*parse_var_name(char *var_name)
{
	int		i;

	i = var_name[0] == '$';
	if (!ft_isalphanum_c(var_name[i]))
		return (NULL);
	while (var_name[i] && ft_isalphanum_c(var_name[i]))
		i++;
	return (ft_strncpy(var_name + (var_name[0] == '$'), i - (var_name[0] == '$')));
}

char	*get_env_variable(t_env *env, char *var_name)
{
	char	*correct_var_name;

	correct_var_name = parse_var_name(var_name);
	while (env && correct_var_name)
	{
		if (ft_strcmp(env->name, correct_var_name))
			return (ft_free(correct_var_name), ft_strcpy(env->content));
		env = env->next;
	}
	ft_free(correct_var_name);
	return (NULL);
}

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s -> %s\n", env->name, env->content);
		env = env->next;
	}
}

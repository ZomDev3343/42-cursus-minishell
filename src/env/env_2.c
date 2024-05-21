/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:28:44 by tohma             #+#    #+#             */
/*   Updated: 2024/05/21 10:13:37 by fbelotti         ###   ########.fr       */
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
	if (!var_name || !ft_isalphanum_c(var_name[i]))
		return (NULL);
	while (var_name[i] && ft_isalphanum_c(var_name[i]))
		i++;
	return (ft_strncpy(var_name + (var_name[0] == '$'),
			i - (var_name[0] == '$')));
}

int	has_env_variable(t_env *env, char *name)
{
	char	*correct_name;

	correct_name = parse_var_name(name);
	while (env && correct_name)
	{
		if (ft_strcmp(env->name, correct_name))
			return (ft_free(correct_name), TRUE);
		env = env->next;
	}
	ft_free(correct_name);
	return (FALSE);
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
		printf("%s=%s\n", env->name, env->content);
		env = env->next;
	}
}

char	**build_env(t_env *env)
{
	int		len;
	t_env	*tmp;
	char	**res;
	int		i;
	char	*tmp_joined;

	len = 0;
	i = -1;
	tmp = env;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	res = (char **) ft_calloc(len + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (++i < len)
	{
		tmp_joined = ft_strjoin(env->name, "=");
		res[i] = ft_strjoin(tmp_joined, env->content);
		free(tmp_joined);
		env = env->next;
	}
	return (res);
}

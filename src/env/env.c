/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:32:05 by tohma             #+#    #+#             */
/*   Updated: 2024/04/21 19:57:56 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*newenv(char *name, char *content)
{
	t_env	*var;

	if (!name || !content)
		return (NULL);
	var = ft_calloc(1, sizeof(t_env));
	if (!var)
		return (NULL);
	var->name = name;
	var->content = content;
	return (var);
}

void	free_env(t_env *env)
{
	if (env->next)
		free_env(env->next);
	free(env->name);
	free(env->content);
	free(env);
}

void	push_env(t_env **env, t_env *env_var)
{
	t_env	*tmp;

	if (!*env)
		*env = env_var;
	else
	{
		tmp = *env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = env_var;
	}
}

t_env	*make_env(char **envp)
{
	t_env	*env;
	int		first_equal_index;

	env = NULL;
	if (!envp || !*envp)
		return (env);
	while (*envp)
	{
		first_equal_index = ft_strchr_i(*envp, '=');
		push_env(&env, newenv(ft_strncpy(*envp, first_equal_index),
				ft_strcpy((*envp) + first_equal_index + 1)));
		envp++;
	}
	return (env);
}

int	remove_env_var(t_env **env, char *var_name)
{
	t_env	*tmp;
	t_env	*tmp_2;

	if (!*env || !var_name)
		return (FALSE);
	tmp = *env;
	if (ft_strcmp(tmp->name, var_name) == 0)
		return (*env = tmp->next, tmp->next = NULL, free_env(tmp), TRUE);
	while (tmp)
	{
		if (ft_strcmp(tmp->next->name, var_name) == 0)
			return (tmp_2 = tmp->next, tmp->next = tmp_2->next,
				tmp_2->next = NULL, free_env(tmp_2), TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

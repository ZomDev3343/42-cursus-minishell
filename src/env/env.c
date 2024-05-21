/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:32:05 by tohma             #+#    #+#             */
/*   Updated: 2024/05/21 15:05:06 by fbelotti         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:32:05 by tohma             #+#    #+#             */
/*   Updated: 2024/05/15 21:24:11 by fbelotti         ###   ########.fr       */
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
	t_env	*current_env;
	t_env	*previous;

	current_env = *env;
	previous = NULL;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, var_name, ft_strlen(var_name)) == 1)
		{
			if (previous == NULL)
				*env = current_env->next;
			else
				previous->next = current_env->next;
			free_env(current_env);
			return (TRUE);
		}
		previous = current_env;
		current_env = current_env->next;
	}
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:32:05 by tohma             #+#    #+#             */
/*   Updated: 2024/06/06 14:47:32 by fbelotti         ###   ########.fr       */
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
	if (!env)
		return ;
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

static char	*get_var_content(char *var_name, char *base_content)
{
	int	shlvl;

	if (ft_strcmp(var_name, "SHLVL"))
	{
		shlvl = ft_atoi(base_content) + 1;
		ft_free(base_content);
		return (ft_itoa(shlvl));
	}
	else
		return (base_content);
}

t_env	*make_env(char **envp)
{
	t_env	*env;
	int		first_equal_index;
	char	*var_name;

	env = NULL;
	if (!envp || !*envp)
		return (env);
	while (*envp)
	{
		first_equal_index = ft_strchr_i(*envp, '=');
		var_name = ft_strncpy(*envp, first_equal_index);
		push_env(&env, newenv(var_name, get_var_content(var_name,
					ft_strcpy((*envp) + first_equal_index + 1))));
		envp++;
	}
	return (env);
}

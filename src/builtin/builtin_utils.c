/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/29 23:16:26 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_current_working_directory(void)
{
	char	*cwd;
	char	buffer[1024];

	if (getcwd(buffer, sizeof(buffer)))
	{
		cwd = ft_strdup(buffer);
		if (!cwd)
			return (NULL);
	}
	else
		return (NULL);
	return (cwd);
}

void	add_env_variable(t_env *env, t_env *env_var)
{
	t_env	*tmp;

	if (!env)
		env = env_var;
	else
	{
		tmp = env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = env_var;
	}
}

/*t_env	*newenv_cd(char *name, char *content)
{
	t_env	*var;

	if (!name || !content)
		return (NULL);
	var = ft_calloc(1, sizeof(t_env));
	if (!var)
		return (NULL);
	var->name = ft_strdup(name);
	var->content = ft_strdup(content);
	return (var);
}*/

void	update_env(char *content, char *name, t_env *env)
{
	//fprintf(stderr, "name : %s content : %s\n", name, content);
	remove_env_var(env, name);
	add_env_variable(env, newenv(name, content));
}

int	remove_env_var(t_env *env, char *var_name)
{
	t_env	*current_env;
	t_env	*previous;

	current_env = env;
	previous = NULL;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, var_name, ft_strlen(var_name)))
		{
			if (previous == NULL)
				env = current_env->next;
			else
				previous->next = current_env->next;
			free(current_env->name);
			free(current_env->content);
			free(current_env);
			return (TRUE);
		}
		previous = current_env;
		current_env = current_env->next;
	}
	return (FALSE);
}

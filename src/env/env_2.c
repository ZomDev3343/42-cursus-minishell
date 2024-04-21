/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:28:44 by tohma             #+#    #+#             */
/*   Updated: 2024/04/21 23:37:44 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_variable(t_env *env, char *var_name)
{
	// TODO
	while (env)
	{
		if (ft_strcmp(env->name, var_name) == 0)
			return (ft_strcpy());
		env = env->next;
	}
	return (NULL);
}

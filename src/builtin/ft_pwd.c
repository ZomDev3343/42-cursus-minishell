/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:05:02 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/13 17:24:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(t_env *env)
{
	t_env	*current_env;

	current_env = env;
	while (current_env)
	{
		if (ft_strncmp(current_env->name, "PATH", 4))
		{
			printf("%s\n", current_env->content);
			return ;
		}
		current_env = current_env->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/13 17:23:41 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_env *env)
{
	t_env	*current_env;

	current_env = env;
	while (current_env)
	{
		printf("%s=", current_env->name);
		printf("%s\n", current_env->content);
		current_env = current_env->next;
	}
}

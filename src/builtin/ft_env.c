/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/28 16:19:32 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_command *cmd, t_env *env)
{
	if (cmd->parts[1] == NULL)
		print_env(env);
	else
		printf("ERROR : env builtin in minishell does not accept arguments.\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/30 23:25:56 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_command *cmd, t_env *env, t_exec *exec)
{
	if (cmd->parts[1] == NULL)
		print_env(env);
	else
		exec->exit_status = 1;
}

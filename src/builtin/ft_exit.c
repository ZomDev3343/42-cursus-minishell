/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/14 15:19:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_command *cmd)
{
	int	status;

	status = 0;
	if (cmd->parts[1])
		status = ft_atoi(cmd->parts[1]);
	exit(status);
}

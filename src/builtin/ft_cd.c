/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/14 15:17:18 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd(t_command *cmd)
{
	if (cmd->parts[1] == NULL)
		chdir(getenv("HOME"));
	else
		chdir(cmd->parts[1]);
}

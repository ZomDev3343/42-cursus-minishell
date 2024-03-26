/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:30:22 by tohma             #+#    #+#             */
/*   Updated: 2024/03/20 16:32:51 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	free_command(t_command *cmd)
{
	int	i;

	i = -1;
	if (!cmd)
		return (FALSE);
	while (++i)
		ft_free(cmd->cmd_args[i]);
	ft_free(cmd);
	return (TRUE);
}

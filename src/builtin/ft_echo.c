/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:46 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/14 17:46:38 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_echo(t_command *cmd)
{
	int	newline_flag;
	int	i;

	newline_flag = 1;
	i = 1;
	if (ft_strncmp(cmd->parts[1], "-n", 2))
	{
		newline_flag = 0;
		i = 2;
	}
	while (cmd->parts[i])
	{
		printf("%s", cmd->parts[i]);
		if (cmd->parts[i + 1])
			printf(" ");
		i++;
	}
	if (newline_flag == 1)
		printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:46 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/12 12:15:33 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_for_n_arg(char *arg)
{
	int	i;

	i = 1;
	if (!arg)
		return (0);
	if (arg[0] == '-')
	{
		while (arg[i] == 'n')
			i++;
		if (i == ft_strlen(arg))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_echo(t_command *cmd)
{
	int	newline_flag;
	int	i;

	newline_flag = 1;
	i = 1;
	if (check_for_n_arg(cmd->parts[1]) == 1)
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
	return (0);
}

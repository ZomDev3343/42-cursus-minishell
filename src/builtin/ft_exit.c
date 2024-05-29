/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/30 01:47:16 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isalpha_c(char c)
{
	return (ft_isalpha(c));
}

int	is_only_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha_c(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_exit_arg(t_command *cmd)
{
	int	arg_nb;

	arg_nb = get_args_nb(cmd);
	if (arg_nb > 1)
	{
		perror(" too many arguments\n");
		exit(1);
	}
	if (arg_nb == 1 && is_only_alpha(cmd->parts[1]) == TRUE)
	{
		perror(" numeric arguments required\n");
		exit(2);
	}
}

void	ft_exit(t_exec *exec, t_command *cmd, t_env *env)
{
	int	status;

	check_exit_arg(cmd);
	if (cmd->parts[1])
		status = ft_atoi(cmd->parts[1]);
	free_command(cmd);
	free_env(env);
	free_pipes(exec->pipes, exec->cmd_nb - 1);
	free(exec->line);
	free(exec);
	rl_clear_history();
	exit(status);
}

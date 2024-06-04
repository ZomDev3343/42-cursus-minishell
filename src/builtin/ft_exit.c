/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/04 12:39:40 by fbelotti         ###   ########.fr       */
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

int	check_exit_arg(t_exec *exec, t_command *cmd)
{
	int	arg_nb;

	arg_nb = get_args_nb(cmd);
	if (arg_nb > 1)
	{
		printf("-minishell: exit: too many arguments\n");
		exec->exit_status = 1;
		return (1);
	}
	if (arg_nb == 1 && is_only_alpha(cmd->parts[1]) == TRUE)
	{
		printf("-minishell: exit: numeric arguments required\n");
		exec->exit_status = 1;
		return (1);
	}
	return (0);
}

int	ft_exit(t_exec *exec, t_command *cmd, t_env *env)
{
	int	status;

	if (exec->exit_status != -1)
		status = exec->exit_status;
	else if (cmd->parts[1])
	{
		if (check_exit_arg(exec, cmd) == 0)
			status = ft_atoi(cmd->parts[1]);
		else
			return (1);
	}
	else
		status = 0;
	free_command(cmd);
	free_env(env);
	free_pipes(exec->pipes, (exec->cmd_nb - 1));
	free(exec->line);
	free(exec);
	rl_clear_history();
	exit(status);
	return (0);
}

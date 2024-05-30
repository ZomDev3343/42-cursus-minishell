/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:04:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/31 00:00:11 by fbelotti         ###   ########.fr       */
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

void	check_exit_arg(t_exec *exec, t_command *cmd, t_env *env)
{
	int	arg_nb;

	arg_nb = get_args_nb(cmd);
	if (arg_nb > 1)
	{
		perror(" too many arguments\n");
		exec->exit_status = 1;
		ft_exit(exec, cmd, env);
	}
	if (arg_nb == 1 && is_only_alpha(cmd->parts[1]) == TRUE)
	{
		perror(" numeric arguments required\n");
		exec->exit_status = 2;
		ft_exit(exec, cmd, env);
	}
}

void	ft_exit(t_exec *exec, t_command *cmd, t_env *env)
{
	int	status;

	if (exec->exit_status != -1)
		status = exec->exit_status;
	else if (cmd->parts[1])
	{
		check_exit_arg(exec, cmd, env);
		status = ft_atoi(cmd->parts[1]);
	}
	if (cmd)
		free_command(cmd);
	if (env)
		free_env(env);
	if (exec->pipes)
		free_pipes(exec->pipes, (exec->cmd_nb - 1));
	if (exec->line)
		free(exec->line);
	if (exec)
		free(exec);
	rl_clear_history();
	exit(status);
}

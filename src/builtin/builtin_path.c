/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:37:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:47 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_in_child(t_command *cmd, t_env *env, t_exec *exec)
{
	int	flag;

	flag = 0;
	if (cmd->builtin_flag == BUILTIN_ECHO)
		flag = ft_echo(cmd);
	else if (cmd->builtin_flag == BUILTIN_PWD)
		flag = ft_pwd();
	else if (cmd->builtin_flag == BUILTIN_ENV)
		flag = ft_env(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_CD)
		flag = ft_cd(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_EXPORT)
		flag = ft_export(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_UNSET)
		flag = ft_unset(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_EXIT)
		flag = ft_exit(exec, cmd, env);
	if (flag == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	builtin_out_child(int i, t_exec *exec, t_command *cmd, t_env *env)
{
	int	flag;

	flag = 0;
	handle_redir_entering_exec(i, exec);
	if (cmd->builtin_flag == BUILTIN_CD)
		flag = ft_cd(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_EXPORT)
		flag = ft_export(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_UNSET)
		flag = ft_unset(cmd, env);
	else if (cmd->builtin_flag == BUILTIN_EXIT)
		flag = ft_exit(exec, cmd, env);
	handle_redir_leaving_exec(i, exec);
	if (flag == 1)
	{
		exec->exit_code = 1;
		exec->error_flag = 1;
	}
	else
		exec->exit_code = 0;
}

int	check_builtin_path(t_command *cmd)
{
	if (cmd->builtin_flag > NOT_A_BUILTIN && cmd->builtin_flag <= BUILTIN_PWD)
		return (0);
	else if (cmd->builtin_flag > BUILTIN_PWD)
		return (1);
	else
		return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:51:54 by tohma             #+#    #+#             */
/*   Updated: 2024/06/08 15:32:53 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_last_status_code(t_exec *exec)
{
	int		status_code;

	status_code = -256;
	if (WIFEXITED(exec->exit_code))
		status_code = WEXITSTATUS(exec->exit_code);
	if (WIFSIGNALED(exec->exit_code))
	{
		status_code = WTERMSIG(exec->exit_code);
		if (status_code != 131)
			status_code += 128;
	}
	return (ft_itoa(status_code));
}

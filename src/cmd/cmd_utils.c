/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:41:11 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/13 11:34:01 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exec	*make_exec_structure(void)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	if (!exec)
	{
		perror("ERROR : allocating exec structure\n");
		exit(EXIT_FAILURE);
	}
	return (exec);
}

int	get_nb_of_commands(t_command *cmd)
{
	int	cmd_nb;

	cmd_nb = 0;
	while (cmd)
	{
		cmd_nb++;
		cmd = cmd->next;
	}
	return (cmd_nb);
}

void	ft_free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_pipes(int **pipes, int pipe_nb)
{
	int	i;

	i = 0;
	while (i < pipe_nb)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

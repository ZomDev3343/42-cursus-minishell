/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:00:10 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/20 16:13:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	**create_pipes(int pipe_nb)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = (int **)malloc(pipe_nb * sizeof(int *));
	while (i < pipe_nb)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) < 0)
		{
			perror("ERROR : while creating a pipe\n");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	handle_redir_leaving_exec(int i, t_exec *exec)
{
	if (i > 0)
		close(exec->pipes[i - 1][0]);
	if (i < exec->cmd_nb - 1)
		close(exec->pipes[i][1]);
	dup2(exec->fd_stdout, STDOUT_FILENO);
	dup2(exec->fd_stdin, STDIN_FILENO);
	close(exec->fd_stdout);
}

void	handle_redir_entering_exec(int i, t_exec *exec)
{
	if (i > 0)
	{
		dup2(exec->pipes[i - 1][0], STDIN_FILENO);
		close(exec->pipes[i - 1][1]);
	}
	if (i < exec->cmd_nb - 1)
	{
		dup2(exec->pipes[i][1], STDOUT_FILENO);
		close(exec->pipes[i][0]);
	}
}

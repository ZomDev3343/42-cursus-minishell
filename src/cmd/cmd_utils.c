/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:41:11 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/12 13:49:04 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	**create_pipes(int pipe_nb, int **pipes)
{
	int	i;

	i = 0;
	pipes = (int **)malloc(pipe_nb * sizeof(int *));
	while (i < pipe_nb)
	{
		pipes[i] = (int *)malloc(2 * sizeof(int));
		if (pipe(pipes[i]) < 0)
		{
			perror("ERROR : while creating a pipe.\n");
			/* free_pipes */
			return ;
		}
		i++;
	}
	return (pipes);
}

void	cleanup_pipes(int **pipes, int pipe_nb)
{
	int	i;

	i = 0;
	while (i < pipe_nb)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	i = 0;
	while (i < pipe_nb)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

t_exec	*make_exec_structure(void)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	if (!exec)
	{
		perror("ERROR : allocating exec structure\n");
		exit(EXIT_FAILURE);
	}
	exec->fd_stdin = dup(STDIN_FILENO);
	exec->fd_stdout = dup(STDOUT_FILENO);
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

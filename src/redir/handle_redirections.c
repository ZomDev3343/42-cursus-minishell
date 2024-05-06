/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:27:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/06 12:51:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_redirections(t_redirections *redir, t_exec *exec)
{
	int	flag;

	flag = 0;
	exec->output_fd = STDOUT_FILENO;
	while (redir)
	{
		if (redir == NULL)
			return (0);
		else if (redir->mode == REDIR_IN)
			flag = handle_input_redirection(redir->path);
		else if (redir->mode == REDIR_OUT)
			flag = handle_output_redirection(redir->path, exec);
		else if (redir->mode == REDIR_APP)
			flag = handle_append_redirection(redir->path);
		/*else if (redir->mode == REDIR_HD)
			flag = handle_here_doc_redirection(redir->path);*/
		redir = redir->next;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	handle_input_redirection(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR : no such file in directory\n");
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("ERROR : no such file in directory\n");
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

int	handle_output_redirection(char *path, t_exec *exec)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("ERROR : no such file in directory\n");
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("ERROR : no such file in directory\n");
		close(fd);
		return (1);
	}
	if (exec->output_fd != STDOUT_FILENO)
		close (exec->output_fd);
	exec->output_fd = fd;
	return (0);
}

int	handle_append_redirection(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("ERROR : while opening file.\n");
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("ERROR : dup2 output.\n");
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

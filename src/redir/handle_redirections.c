/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:27:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/03 18:02:11 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_redirections(t_redirections *redir)
{
	int	flag;

	flag = 0;
	if (redir == NULL)
		return (0);
	else if (redir->mode == REDIR_IN)
		flag = handle_input_redirection(redir->path);
	else if (redir->mode == REDIR_OUT)
		flag = handle_output_redirection(redir->path);
	else if (redir->mode == REDIR_APP)
		flag = handle_append_redirection(redir->path);
	/*else if (redir->mode == REDIR_HD)
		flag = handle_here_doc_redirection(redir->path);*/
	if (flag == 1)
	{
		perror("ERROR : while handling redirections.\n");
		return (1);
	}
	return (0);
}

int	handle_input_redirection(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR : while opening file.\n");
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("ERROR : dup2 input.\n");
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

int	handle_output_redirection(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

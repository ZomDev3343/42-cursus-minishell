/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:27:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/27 12:28:26 by fbelotti         ###   ########.fr       */
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
		else if (redir->mode == REDIR_HD)
			flag = handle_here_doc_redirection(redir->path, exec);
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
		perror("ERROR : using dup2 for STDIN\n");
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
		perror("ERROR : using dup2 for STDOUT\n");
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
		perror("ERROR : using dup2 for APPEND\n");
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

int	handle_here_doc_redirection(char *path, t_exec *exec)
{
	char	*line;

	exec->input_fd = open("here_doc.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (exec->input_fd == -1)
	{
		perror("ERROR : can't access here_doc\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (hd_strncmp(line, path, ft_strlen(path)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, exec->input_fd);
		free(line);
	}
	close(exec->input_fd);
	exec->input_fd = open("here_doc.txt", O_RDONLY);
	dup2(exec->input_fd, STDIN_FILENO);
	close(exec->input_fd);
	unlink("here_doc.txt");
	return (0);
}

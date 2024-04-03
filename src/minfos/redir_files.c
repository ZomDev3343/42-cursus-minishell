/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:37:20 by truello           #+#    #+#             */
/*   Updated: 2024/04/03 13:46:25 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir_files	*newrf(char *file_path, t_redirect_mode mode)
{
	t_redir_files	*res;

	res = ft_calloc(1, sizeof(t_redir_files));
	if (!res)
		return (NULL);
	res->file_path = file_path;
	res->mode = mode;
	res->next = NULL;
	return (res);
}

void	push_redir_file(t_redir_files **rf_struct, char *file_path,
	t_redirect_mode mode)
{
	t_redir_files	*tmp;

	if (!rf_struct)
		return ;
	if (!*rf_struct)
		*rf_struct = newrf(file_path, mode);
	else
	{
		tmp = *rf_struct;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newrf(file_path, mode);
	}
}

void	free_redir_files(t_redir_files **files)
{
	if ((*files)->next)
		free_redir_files(&((*files)->next));
	ft_free((*files)->file_path);
	ft_free(*files);
	files = NULL;
}

void	print_redir_files(t_redir_files *files)
{
	t_redir_files	*tmp;

	if (!files)
		return ;
	tmp = files;
	printf("--- PRINT REDIR FILES ---\n");
	while (tmp)
	{
		printf("FP: %s, Mode: %d\n", files->file_path, files->mode);
		tmp = tmp->next;
	}
	printf("--- PRINT REDIR FILES ---\n");
}

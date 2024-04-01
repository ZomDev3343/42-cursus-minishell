/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:37:20 by truello           #+#    #+#             */
/*   Updated: 2024/04/01 16:02:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir_files	*newrf(char *file_path)
{
	t_redir_files	*res;

	res = ft_calloc(1, sizeof(t_redir_files));
	if (!res)
		return (NULL);
	res->file_path = file_path;
	res->next = NULL;
	return (res);
}

void	push_redir_file(t_redir_files **rf_struct, char *file_path)
{
	t_redir_files	*tmp;

	if (!rf_struct)
		return ;
	if (!*rf_struct)
		*rf_struct = newrf(file_path);
	else
	{
		tmp = *rf_struct;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newrf(file_path);
	}
}

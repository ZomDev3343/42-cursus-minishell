/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minfos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:09:35 by truello           #+#    #+#             */
/*   Updated: 2024/04/03 16:04:12 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_minishell	*init_minishell(void)
{
	t_minishell	*minfos;

	minfos = (t_minishell *) ft_calloc(1, sizeof(t_minishell));
	if (!minfos)
		return (NULL);
	minfos->input_files = NULL;
	minfos->output_files = NULL;
	minfos->env = NULL;
	return (minfos);
}

void	clear_minfos_rfiles(t_minishell *minfos)
{
	free_redir_files(minfos->input_files);
	free_redir_files(minfos->output_files);
	minfos->input_files = NULL;
	minfos->output_files = NULL;
}

void	free_minfos(t_minishell *minfos)
{
	clear_minfos_rfiles(minfos);
	if (!minfos->env)
		free_parts(minfos->env);
	if (!minfos)
		free(minfos);
}

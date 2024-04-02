/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minfos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:09:35 by truello           #+#    #+#             */
/*   Updated: 2024/04/02 16:06:44 by truello          ###   ########.fr       */
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

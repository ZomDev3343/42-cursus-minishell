/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:07 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 17:43:38 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	get_redirection_char(int mode)
{
	if (mode == REDIR_IN || mode == REDIR_HD)
		return ('<');
	else
		return ('>');
}

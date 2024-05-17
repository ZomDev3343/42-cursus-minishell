/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:51:54 by tohma             #+#    #+#             */
/*   Updated: 2024/05/17 14:38:23 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_last_status_code(void)
{
	int		status_code;

	status_code = -256;
	if (WIFEXITED(0))
		status_code = WEXITSTATUS(0);
	if (WIFSIGNALED(0))
	{
		status_code = WTERMSIG(0);
		if (status_code != 131)
			status_code += 128;
	}
	return (ft_itoa(status_code));
}

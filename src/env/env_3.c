/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:51:54 by tohma             #+#    #+#             */
/*   Updated: 2024/06/06 19:25:53 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_last_status_code(void)
{
	int		status_code;
	int		base_status;

	status_code = -256;
	base_status = 0;
	if (WIFEXITED(base_status))
		status_code = WEXITSTATUS(base_status);
	if (WIFSIGNALED(base_status))
	{
		status_code = WTERMSIG(base_status);
		if (status_code != 131)
			status_code += 128;
	}
	return (ft_itoa(status_code));
}

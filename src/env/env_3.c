/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:51:54 by tohma             #+#    #+#             */
/*   Updated: 2024/06/04 15:28:52 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_last_status_code(void)
{
	int		status_code;

	status_code = -256;
	if (WIFEXITED(basic_status))
		status_code = WEXITSTATUS(basic_status);
	if (WIFSIGNALED(basic_status))
	{
		status_code = WTERMSIG(basic_status);
		if (status_code != 131)
			status_code += 128;
	}
	return (ft_itoa(status_code));
}

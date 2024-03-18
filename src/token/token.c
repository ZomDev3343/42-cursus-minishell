/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:28 by truello           #+#    #+#             */
/*   Updated: 2024/03/18 13:17:58 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_del(char *delimiter, char c)
{
	while (*delimiter)
	{
		if (c == *delimiter)
			return (1);
		delimiter++;
	}
	return (0);
}

int	count_tokens(char *str, const char *delimiter)
{
	int	i;

	i = -1;
	if (!str || !delimiter || delimiter[0] == '\0')
		return (0);
	while (i++)
	{
	}
}


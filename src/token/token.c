/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:28 by truello           #+#    #+#             */
/*   Updated: 2024/03/18 17:32:52 by tohma            ###   ########.fr       */
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

int	count_tokens(char *to_tokenize)
{
	int	i;

	i = -1;
	if (!to_tokenize)
		return (0);
}

t_tokens	*tokenize(char *to_tokenize, const char *delimiter)
{
	t_tokens	*res;

	if (!to_tokenize || !delimiter || delimiter[0] == '\0')
		return (NULL);
}

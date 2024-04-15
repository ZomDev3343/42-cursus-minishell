/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:59:48 by truello           #+#    #+#             */
/*   Updated: 2024/04/15 14:17:15 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*newtoken(char *data, int type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->data = data;
	token->type = type;
	return (token);
}

t_token	*tokenize(char *line)
{
	t_token	*token;
	int		i;

	token = NULL;
	i = ft_nstrchr_i(line, ' ') - 1;
	while (line[i])
	{
		token
	}

}

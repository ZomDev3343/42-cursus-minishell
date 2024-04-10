/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:28 by truello           #+#    #+#             */
/*   Updated: 2024/04/08 14:27:29 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*newtoken(char *data, int flag)
{
	t_token	*res;

	res = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!res)
		return (NULL);
	res->data = data;
	res->flag = flag;
	return (res);
}

void	free_token(t_token *token)
{
	if (!token)
		return ;
	free(token->data);
	free(token);
}

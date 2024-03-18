/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:13:42 by tohma             #+#    #+#             */
/*   Updated: 2024/03/15 18:13:43 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_tokens(char *to_tokenize)
{
	int	i;

	i = -1;
	if (!to_tokenize)
		return (0);
	while(to_tokenize[++i] == ' ');
	while (to_tokenize[i])
	{
		if (i > 0 && to_tokenize[i] == ' ')
		{
			
		}
		i++;
	}
}

t_tokens	tokenize(char *to_tokenize, const char *delimiter)
{
	t_tokens	res;

}
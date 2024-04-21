/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by tohma             #+#    #+#             */
/*   Updated: 2024/04/21 20:28:13 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Takes a pointer on a quote char and search for its twin
 * @return (int) Index of the twin quote
*/
int	is_quote_closed(char *str)
{
	int		closed;
	char	quote;
	int		i;

	closed = 0;
	quote = *str;
	i = 0;
	while (str[++i])
		if (str[i] == quote)
			return (i);
	return (0);
}

char	*rem_double_quotes(char *str, t_env *env)
{
	
}

char	*rem_single_quotes(char *str)
{
	
}

char	*rem_quotes(char *str, t_env *env)
{
	t_string_part	*parts;
	int				i;

	i = -1;
	while (str[++i])
	{
		
	}
	
}

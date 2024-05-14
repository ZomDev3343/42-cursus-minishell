/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by tohma             #+#    #+#             */
/*   Updated: 2024/05/14 15:23:09 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Takes a pointer on a quote char and search for its twin
 * @return (int) Index of the twin quote
*/
int	is_quote_closed(char *str)
{
	char	quote;
	int		i;

	quote = *str;
	i = 0;
	while (str[++i])
		if (str[i] == quote)
			return (i);
	return (0);
}

static int	rem_double_quotes(t_string_part **parts, char *str, t_env *env)
{
	int	end_quote;

	end_quote = is_quote_closed(str);
	if (!end_quote)
		return (-1);
	if (end_quote > 1)
		parse_word(parts, str + 1, env);
	return (end_quote + (end_quote == 1));
}

static int	rem_single_quotes(t_string_part **parts, char *str)
{
	int	end_quote;

	end_quote = is_quote_closed(str);
	if (!end_quote)
		return (-1);
	if (end_quote > 1)
		push_str_part(parts, ft_strncpy(str + 1, end_quote - 1));
	return (end_quote + (end_quote == 1));
}

char	*rem_quotes(char *str, t_env *env)
{
	t_string_part	*parts;
	char			*res;
	int				i;
	int				quote_end;

	parts = NULL;
	i = -1;
	while (str && str[++i])
	{
		quote_end = 0;
		if (str[i] == '\'')
			quote_end = rem_single_quotes(&parts, str + i);
		else if (str[i] == '\"')
			quote_end = rem_double_quotes(&parts, str + i, env);
		else
		{
			parse_word_nquotes(&parts, str + i, env);
			i += ft_strchr_quotes(str + i) - 1;
		}
		if (quote_end == -1)
			break ;
		if (quote_end > 0)
			i += quote_end - 1;
	}
	return (res = build_str(parts), res);
}

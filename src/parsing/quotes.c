/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:02:09 by tohma             #+#    #+#             */
/*   Updated: 2024/04/23 14:25:38 by truello          ###   ########.fr       */
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
	int	i;
	int	last_cpy_index;

	end_quote = is_quote_closed(str);
	if (!end_quote)
		return (-1);
	i = 0;
	last_cpy_index = 1;
	while (++i < end_quote)
	{
		if (str[i] == '$' && i + 1 < end_quote)
		{
			push_str_part(parts,
				ft_strncpy(str + last_cpy_index, i - last_cpy_index));
			push_str_part(parts, get_env_variable(env, str + i));
			i += ft_strchr_nalphanum(str + i + 1);
			last_cpy_index = i + 1;
		}
	}
	if (i - last_cpy_index > 0)
		push_str_part(parts,
			ft_strncpy(str + last_cpy_index, i - last_cpy_index));
	return (end_quote);
}

static int	rem_single_quotes(t_string_part **parts, char *str)
{
	int	end_quote;

	end_quote = is_quote_closed(str);
	if (end_quote <= 1)
		return (-1);
	push_str_part(parts, ft_strncpy(str + 1, end_quote - 1));
	return (end_quote);
}

char	*rem_quotes(char *str, t_env *env)
{
	t_string_part	*parts;
	char			*res;
	int				i;
	int				quote_end;

	parts = NULL;
	i = -1;
	while (str[++i])
	{
		quote_end = 0;
		if (str[i] == '\'')
			quote_end = rem_single_quotes(&parts, str + i);
		else if (str[i] == '\"')
			quote_end = rem_double_quotes(&parts, str + i, env);
		else
		{
			push_str_part(&parts, ft_strcpy_until_quote(str + i));
			i += ft_strchr_quotes(str + i);
		}
		if (quote_end == -1)
			break ;
		i += quote_end;
	}
	return (res = build_str(parts), res);
}
